
OBJS = Main Tree TreeGen TreeExtract
CC = g++
CFLAGS = -o 
OFLAGS = -c 

Out: $(OBJS)	 
		$(CC) $(OBJS) $(CFLAGS) Out

Main : Main.cpp 
		$(CC) $(OFLAGS) Main.cpp $(CFLAGS) Main

Tree : Tree.cpp Tree.h
		$(CC) $(OFLAGS) Tree.cpp $(CFLAGS) Tree		 
TreeGen : TreeGen.cpp TreeGen.h Tree.h	
			$(CC) $(OFLAGS) TreeGen.cpp $(CFLAGS) TreeGen 
TreeExtract : TreeExtract.cpp TreeExtract.h Tree.h	
				$(CC) $(OFLAGS) TreeExtract.cpp $(CFLAGS) TreeExtract  
