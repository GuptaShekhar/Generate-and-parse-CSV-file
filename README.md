# Generate-and-parse-CSV-file
### CSV (Comma Separated Values)
CSV is a simple file format used to store tabular data such as a spreadsheet or a database. The data fields in a CSV file are separated/delimited by a comma (‘,‘) and the individual rows are separated by a newline (‘\n’).

The create operation is similar to creating a text file, i.e. input data from the user and write it to the csv file using the file pointer and appropriate delimiters(‘, ‘) between different columns and ‘\n’ after the end of each row.

In reading a CSV file, the following approach is implemented:-

1. Using getline(), file pointer and ‘\n’ as the delimiter, read an entire row and store it in a string variable.
2. Using stringstream, seperate the row into words.

To get a random number, I have used a srand(clock()), that provide random number without causing any repetition.

The program take a user input from command line.
generateCSVFile.cpp ask for 3 input, first input is number of column, second input is for number of row and third input for CSV filename.
#### command line input format-   ./execfile1  20 40 csvFile
parseCSVFile  ask for one input, i.e. name of csvFile.
#### command line input format-   ./execfile2  csvFile


### Program
There is a set of weather readings from various cities recorded as a CSV file (comma separated values file). 
    A sample file is shown below 

    City, Jan01, Jan02, Jan03, Jan04
    Delhi, 40, 41, 42, 43
    Beijing, 20, 21, 25, 30
    Cairo, 40, 39, 38, 42

    Write 2 separate programs
    1) First program should generate a sample CSV for different cities use city names as "c1", "c2" etc ..., for day use "d1", "d2" etc ...
       The temperature readings should range between -10 to 45, generate random temperature readings for this
 
       Program should take 3 arguments e.g as follows and use the same flags cols, rows, outputfile shown below
       generate_csv is the name of the executable, 20 is the number of columns 40 is the number of rows to generate, sample1.csv is the name of output file your program will produce

       "generate_csv cols=20 rows=40 outputfile=sample1.csv"
       

    2) Second program should read the sample program read in step 1) and do the following
       Generate row wise mean for a particular city
       Generate row wise median for a particular city
       Generate row wise standard deviation for a particular city
       Do this for all cities one by one and print the calculated values

       Generate column wise mean for a particular city
       Generate column wise median for a particular city
       Generate column wise standard deviation for a particular city
       Do this for all columns one by one and print the calculated values

       Program should take 3 arguments as follows
       "print_stats cols=20 rows=40 inputfile=sample1.csv"

       Output should be as follows:
       ROW wise stats
       ==============
       c1 mean is 20
       c1 median is 20
       c1 standard deviation is 0
       c2 mean is 20
       c2 median is 20
       c2 standard deviation is 0

       COLUMN wise stats
       =================
       d1 mean is 20
       d1 median is 20
       d1 standard deviation is 0
       d2 mean is 20
       d2 median is 20
       d2 standard deviation is 0

