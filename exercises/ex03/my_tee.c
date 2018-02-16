// Implementation of the tee terminal command
// tee [OPTION] ... [FILE] ...
// Copies standard input to each file specified and also to standard output
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

static int help_flag, version_flag;
void help_disp();
void version_disp();

// -a, --append
//               append to the given FILEs, do not overwrite

//        -i, --ignore-interrupts
//               ignore interrupt signals

//        -p     diagnose errors writing to non pipes

//        --output-error[=MODE]
//               set behavior on write error.  See MODE below

//        --help display this help and exit

//        --version
//               output version information and exit
// MODE determines behavior with write errors on the outputs:
//        'warn' diagnose errors writing to any output

//        'warn-nopipe'
//               diagnose errors writing to any output not a pipe

//        'exit' exit on error writing to any output

//        'exit-nopipe'
//               exit on error writing to any output not a pipe

//        The default MODE for the -p option is 'warn-nopipe'.  The default
//        operation when --output-error is not specified, is to exit
//        immediately on error writing to a pipe, and diagnose errors writing
//        to non pipe outputs.

int main(int argc, char *argv[]) {
	int c;

	while (1)
    {
      static struct option long_options[] =
        {
          /* These options set a flag. */
          {"help",     no_argument,      &help_flag, 1},
          {"version",  no_argument,		 &version_flag,  1},
          /* These options don’t set a flag.
             We distinguish them by their indices. */
          {"append",  no_argument,       0, 'a'},
          {"output-error", required_argument, 0, 'o'},
          {"ignore-interrupts", no_argument, 0, 'i'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "ao:ip",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

    switch (c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'a':
          printf("option -a\n");
          break;

        case 'o':
          printf ("option -o with value `%s'\n", optarg);
          break;

        case 'i':
          printf ("option -i\n");
          break;

        case 'p':
          printf ("option -p\n");
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
	}

	if (help_flag) {
    	help_disp();
    	exit(0);
	}
	if (version_flag) {
		version_disp();
		exit(0);
	}

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}

// Prints the version when the version flag is specified
void version_disp() {
	puts("Version:");
	puts("\tKeil 1.0, Spring 2018");
}

// Prints all the help information when help flag is specified
void help_disp() {
	puts("NAME");
	puts("\ttee - read from standard input and write to standard output and files");
	puts("SYNOPSIS");
	puts("\ttee [OPTION]... [FILE]...");
	puts("DESCRIPTION");
	puts("\tCopy standard input to each FILE, and also to standard output.");
	puts("\t\t-a, --append");
	puts("\t\t\tappend to the given FILEs, do not overwrite");
	puts("");
	puts("\t\t-i, --ignore-interrupts");
	puts("\t\t\tignore interupt signals");
	puts("");
	puts("\t\t-p");
	puts("\t\t\tdiagnose errors writing to non pipes");
	puts("");
	puts("\t\t--output-error[=MODE]");
	puts("\t\t\tset behavior on write error.  See MODE below");
	puts("");
	puts("\t\t--help");
	puts("\t\t\tdisplay this help and exit");
	puts("");
	puts("\t\t--version");
	puts("\t\t\toutput version information and exit");
	puts("");

	puts("MODE determines behavior with write errors and outputs:");
	puts("\t\t'warn'");
	puts("\t\t\tdiagnose errors writing to any output");
	puts("");
	puts("\t\t'warn-nopipe'");
	puts("\t\t\tdiagnose erros writing to any output not a pipe");
	puts("");
	puts("\t\t'exit'");
	puts("\t\t\texit on error writing to any output");
	puts("");
	puts("\t\t'exit-nopipe'");
	puts("\t\t\texit on error writing to any output not a pipe");
	puts("");
	puts("\t\tThe default MODE for the -p option is 'warn-nopipe'.  The default");
	puts("\t\toperation when --output-error is not specified, is to exit");
	puts("\t\timmediately on error writing to a pipe, and diagnose errors writing");
	puts("\t\tto non pipe outputs.");
}