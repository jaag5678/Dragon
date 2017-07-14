
OBJS = Main Tree TreeGen TreeExtract FA
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
FA : Fa.h Fa.cpp Tree.h
		$(CC) $(OFLAGS) Fa.cpp $(CFLAGS) FA