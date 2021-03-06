To Run Mesquite on Linux

To run Mesquite, you need Java installed.  The version of Mesquite you have here runs on Java 1.6 or higher.

Run Mesquite by double clicking mesquite.sh or running mesquite.sh from the command line like this:
	./mesquite.sh

Alternatively, run it from the command line by cd'ing into Mesquite_Folder and then giving a command like this:

   java -Xmx1000M -Xss4m -Djava.library.path=lib -Djri.ignore.ule="yes" -jar Mesquite.jar

The part -Xmx1000M indicates how much heap memory to give to Mesquite in general. With more heap memory Mesquite can handle more trees, bigger matrices, bigger charts, and so on.
The part -Xss4m indicates how much stack memory to give to each thread.  With more stack memory, Mesquite can handle bigger trees, e.g. more than 5000 taxa.  To be able to handle 10000 taxa, you may need to increase this to 4m

Here is an example configuration:

	java -Xmx4000M -Xss16m -d64 -Djava.library.path=lib -Djri.ignore.ule="yes" -jar Mesquite.jar

This gives much memory to Mesquite, but 4000 MB (= 4 GB) memory exceeds the ability of 32 bit Java.  For that reason the command -d64 was added, to indicate you want to use 64 bit java.  

