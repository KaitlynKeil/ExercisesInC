// Implementation of the tee terminal command
// tee [OPTION] ... [FILE] ...
// Copies standard input to each file specified and also to standard output
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

static int append_flag;
static int error_mode;
int help_disp();
int version_disp();
int tee_loop(int nfiles, char **files);

enum output_error {
	  output_error_default,		 /* warn on non pipe, exit on pipe */
      output_error_warn,         /* warn on EPIPE, but continue.  */
      output_error_warn_nopipe,  /* ignore EPIPE, continue.  */
      output_error_exit,         /* exit on any output error.  */
      output_error_exit_nopipe   /* exit on any output error except EPIPE.  */	
};

static struct option long_options[] = 
		{
			{"help",              no_argument,       0,     'h'},
			{"version",           no_argument,       0,     'v'},
			{"append",            no_argument,       0,     'a'},
			{"output-error",      required_argument, 0,     'o'},
			{"ignore-interrupts", no_argument,       0,     'i'},
			{0, 0, 0, 0}
		};

/* main sets up the system for the loop */
int main(int argc, char *argv[]) {
	int c, exitval; // keeps track of status
	error_mode = output_error_default; // Unless set otherwise, output the default errors
	while((c = getopt_long (argc, argv, "ahvo:ip", long_options, NULL)) != -1) {
		// as long as there is an argument to read, keep reading arguments
		switch (c) {
			case 'a':
				append_flag = 1;
				break;

			case 'h':
				exit(help_disp());

			case 'v':
				exit(version_disp());

			case 'o':
	            /* Assigns the mode for error behaviour */
				if(strcmp(optarg, "warn") == 0) {
					error_mode = output_error_warn;
				}
				else if(strcmp(optarg, "warn-nopipe") == 0) {
					error_mode = output_error_warn_nopipe;
				}
				else if(strcmp(optarg, "exit") == 0) {
					error_mode = output_error_exit;
				}
				else if(strcmp(optarg, "exit-nopipe") == 0) {
					error_mode = output_error_exit_nopipe;
				}
				else {
					puts("Invalid error mode");
					exit(1);
					}
	            break;

	        case 'i':
	        	printf("Unimplemented ignore-interrupts\n");
	        	break;

	        case 'p':
	        	error_mode = output_error_warn_nopipe;
	        	break;

	        case '?':
	        	/* error already displayed by getopt_long */
	        	break;

	        default:
	        	abort();
		}
	}

	// Do the functionality
	exitval = tee_loop(argc - optind, &argv[optind]);
	
	return exitval;
}

// Prints the version when the version flag is specified
int version_disp() {
	puts("Version:");
	puts("\tKeil 1.0, Spring 2018");
	return 0;
}

// Prints all the help information when help flag is specified
int help_disp() {

    FILE *fptr;
 
    char filename[100] = "help.txt", c;
 
    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
 
    fclose(fptr);
    return 0;
}

/* Open the files and begin to read information */
int tee_loop(int nfiles, char **files) {
	FILE** filenames = malloc(sizeof(FILE*) * (nfiles));  // Set up space for files
	int i, wval; // Index and status check
	char rval; // fgets status check
	char line[256]; // maximum line length
	char const *read_mode = append_flag ? "a" : "w"; // Either append or don't

	filenames[0] = stdout; // set the first argument to stdout

	for(i = 1; i <= nfiles; i++) {
		// Open all the files
		filenames[i] = fopen(files[i - 1], read_mode);
		if (!filenames[i]) { // If the file can't be opened/made, error
    		printf("error: cannot open file %s\n", files[i-1]);
    		if(error_mode == output_error_exit || output_error_exit_nopipe)
  		  		{exit(1);} // error out if output error exit is true
  		}
  	}
  	while (fgets(line, sizeof(line), stdin)){ // as long as we haven't hit null, keep reading
  		for(i = 0; i <= nfiles; i++) { // for everything (stdout and all files), write
  			if(filenames[i] && (wval = fputs(line, filenames[i])) != EOF) { // while there are actual files and we haven't hit an error, keep going
  				// This part was taken from one of the professional website, as I was having issues figuring out error checking
  				int fail = errno != EPIPE || (error_mode == output_error_exit
                                          || error_mode == output_error_warn);
	            if (filenames[i] == stdout) {
	            	clearerr (stdout); /* Avoid redundant close_stdout diagnostic.  */
	            }
	            if (fail && error_mode == output_error_exit
	                       || error_mode == output_error_exit_nopipe){
	                printf("write error to %s\n", files[i-1]);
	            	exit(1);
	            }
  			}
  		}
  	}
  	// If we didn't hit the end of the file, there was a read error somewhere in there
  	if (!feof(stdin)) {
  		puts("read error");
  		exit(1);
  	}

  	for(i = 1; i <= nfiles; i++) {
  		// Something in here is throwing an error. It works, but there is a double free error thrown
  		// if multiple files are called.
  		if(NULL != filenames[i]) {
  			if(fclose(filenames[i]) != 0) {
  				puts("error closing");
  				exit(1);
  			}
  		}
  	}
  	return 1;
}