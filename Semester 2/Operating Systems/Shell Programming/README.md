
***Operating Systems: UNIX Shell Programming Practice Problems***

CREDITS: Conf. Dr. Rareș Boian, BBU Cluj-Napoca

The commands suggested below are not all required, nor are they the only way to solve the problem. Please try to find alternative solutions, as that will help expand your knowledge. The expected results are based on the test data files below:

    df.fake - Use command "cat df.fake" instead of command "df -BM"
    dir.zip - For problems requiring a directory with files, extract this archive and use its content.
    last.fake - Use command "cat last.fake" instead of command "last"
    passwd.fake - Fake /etc/passwd
    ps.fake - Use command "cat ps.fake" instead of command "ps -ef"
    who.fake - Use command "cat who.fake" instead of command "who"

# 	Problem 	Suggested Commands 	Expected Result
(1) 	Display a report showing the full name of all the users currently connected, and the number of processes belonging to each of them. 	who, ps, finger, grep, while, wc

bradu 2
horea 2
rares 3

(2) 	Find recursively in a directory all ".c" files having more than 500 lines. Stop after finding 2 such files. 	find, wc, expr, while, break

dir/11.c \
dir/d/a/13.c

(3) 	Find recursively in a directory, all the files with the extension ".log" and sort their lines (replace the original file with the sorted content). 	find, sort, mv, rm 	The *.log files in test directory "dir" should be all sorted.

(4) 	Find recursively in a given directory all the symbolic links, and report those that point to files/directories that no longer exist. Use operator -L to test if a path is a symbolic link, and operator -e to test if it exists (will return false if the target to which the link points does not exist) 	find, if 	

(5) 	Write a script that receives dangerous program names as command line arguments. The script will monitor all the processes in the system, and whenever a program known to be dangerous is run, the script will kill it and display a message. 	while, ps, sleep, grep, kill, true

(6) 	Find recursively in a directory, all the files that have write permissions for everyone. Display their names, and the permissions before and after removing the write permission for everybody. You will need to use chmod's symbolic permissions mode, instead of the octal mode we have used in class. The the chmod manual for details. 	find, chmod, ls

-rwxrwxrwx dir/d/c/b/15.c

-rwxrwxr-x dir/d/c/b/15.c

-rwxr---w- dir/d/b/6.txt

-rwxr----- dir/d/b/6.txt

-rwx-w-rw- dir/c/b/9.sh

-rwx-w-r-- dir/c/b/9.sh

(7) 	Consider a file containing a username on each line. Generate a comma-separated string with email addresses of the users that exist. The email address will be obtained by appending "@scs.ubbcluj.ro" at the end of each username. Make sure the generated string does NOT end in a comma. 	for, finger, grep, sed 	Input file

a
b
c

should result in output

a@scs.ubbcluj.ro,b@scs.ubbcluj.ro,c@scs.ubbcluj.ro

(8) 	Display all the mounted file systems who are either smaller than than 1GB or have less than 20% free space. 	df, awk, sed

/dev \
/run \
/dev/shm \
/run/lock \
/sys/fs/cgroup \
/run/user/1000 \
/home/rares/osvm 

(9) 	Write a script that finds in a given directory hierarchy, all duplicate files and displays their paths. Hint: use checksums to detect whether two files are identical. 	find, md5sum, for, sed, awk, sort, uniq, head, tail

(10) 	Display the session count and full names of all the users who logged into the system this month, sorting the output by the session count in descending order. Use the -s and/or -t options of command last to get this month's sessions, and the command date to generate the required timestamp in the expected format. Hint: 	date, last, grep, sort, uniq 	

