{"changed":true,"filter":false,"title":"fifteen.c","tooltip":"/pset3/fifteen/fifteen.c","value":"/**\n * fifteen.c\n *\n * Computer Science 50\n * Problem Set 3\n *\n * Implements Game of Fifteen (generalized to d x d).\n *\n * Usage: fifteen d\n *\n * whereby the board's dimensions are to be d x d,\n * where d must be in [DIM_MIN,DIM_MAX]\n *\n * Note that usleep is obsolete, but it offers more granularity than\n * sleep and is simpler to use than nanosleep; `man usleep` for more.\n */\n \n#define _XOPEN_SOURCE 500\n\n#include <cs50.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <unistd.h>\n\n// constants\n#define DIM_MIN 3\n#define DIM_MAX 9\n\n// board\nint board[DIM_MAX][DIM_MAX];\n\n// dimensions\nint d;\n\n// prototypes\nvoid clear(void);\nvoid greet(void);\nvoid init(void);\nvoid draw(void);\nbool move(int tile);\nbool won(void);\n\nint main(int argc, string argv[])\n{\n    // ensure proper usage\n    if (argc != 2)\n    {\n        printf(\"Usage: fifteen d\\n\");\n        return 1;\n    }\n\n    // ensure valid dimensions\n    d = atoi(argv[1]);\n    if (d < DIM_MIN || d > DIM_MAX)\n    {\n        printf(\"Board must be between %i x %i and %i x %i, inclusive.\\n\",\n            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);\n        return 2;\n    }\n\n    // open log\n    FILE* file = fopen(\"log.txt\", \"w\");\n    if (file == NULL)\n    {\n        return 3;\n    }\n\n    // greet user with instructions\n    greet();\n\n    // initialize the board\n    init();\n\n    // accept moves until game is won\n    while (true)\n    {\n        // clear the screen\n        clear();\n\n        // draw the current state of the board\n        draw();\n\n        // log the current state of the board (for testing)\n        for (int i = 0; i < d; i++)\n        {\n            for (int j = 0; j < d; j++)\n            {\n                fprintf(file, \"%i\", board[i][j]);\n                if (j < d - 1)\n                {\n                    fprintf(file, \"|\");\n                }\n            }\n            fprintf(file, \"\\n\");\n        }\n        fflush(file);\n\n        // check for win\n        if (won())\n        {\n            printf(\"ftw!\\n\");\n            break;\n        }\n\n        // prompt for move\n        printf(\"Tile to move: \");\n        int tile = GetInt();\n        \n        // quit if user inputs 0 (for testing)\n        if (tile == 0)\n        {\n            break;\n        }\n\n        // log move (for testing)\n        fprintf(file, \"%i\\n\", tile);\n        fflush(file);\n\n        // move if possible, else report illegality\n        if (!move(tile))\n        {\n            printf(\"\\nIllegal move.\\n\");\n            usleep(500000);\n        }\n\n        // sleep thread for animation's sake\n        usleep(500000);\n    }\n    \n    // close log\n    fclose(file);\n\n    // success\n    return 0;\n}\n\n/**\n * Clears screen using ANSI escape sequences.\n */\nvoid clear(void)\n{\n    printf(\"\\033[2J\");\n    printf(\"\\033[%d;%dH\", 0, 0);\n}\n\n/**\n * Greets player.\n */\nvoid greet(void)\n{\n    clear();\n    printf(\"WELCOME TO GAME OF FIFTEEN\\n\");\n    usleep(2000000);\n}\n\n/**\n * Initializes the game's board with tiles numbered 1 through d*d - 1\n * (i.e., fills 2D array with values but does not actually print them).  \n */\nvoid init(void)\n{\n    // TODO\n    //int board[d][d];\n    int max=(d*d)-1;\n    if(d%2==0)\n    {\n        for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                board[i][j]=max;\n                max--;\n            }\n        }\n        board[d-1][d-3]=1;\n        board[d-1][d-2]=2;\n        \n    }\n    else\n    {\n        int max=(d*d)-1;\n        for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                board[i][j]=max;\n                max--;\n            }\n        }\n    }\n    \n}\n\n/**\n * Prints the board in its current state.\n */\nvoid draw(void)\n{\n    // TODO\n    for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                if(board[i][j]==0)\n                {\n                    printf(\" __ \");\n                }\n                else\n                {\n                    printf(\"  %i  \",board[i][j]);\n                }\n            }\n            printf(\"\\n\");\n        }\n}\n\n/**\n * If tile borders empty space, moves tile and returns true, else\n * returns false. \n */\nbool move(int tile)\n{\n    // TODO\n    int pos_x,pos_y,temp;\n    for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                if(board[i][j]==0)\n                {\n                    pos_x=i;\n                    pos_y=j;\n                }\n            }\n            \n        }\n\n    \n    for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                if(board[i][j]==tile)\n                {\n                    if(board[pos_x+1][pos_y]==tile||board[pos_x-1][pos_y]==tile||board[pos_x][pos_y+1]==tile||board[pos_x][pos_y-1]==tile)\n                    {\n                        temp=board[pos_x][pos_y];\n                        board[pos_x][pos_y]=board[i][j];\n                        board[i][j]=temp;\n                        return true;\n                    }\n                }\n            }\n                    \n        }\n        \n    return false;\n\n}\n\n/**\n * Returns true if game is won (i.e., board is in winning configuration), \n * else false.\n */\nbool won(void)\n{\n    // TODO\n    int min=1;\n    for(int i=0;i<d;i++)\n        {\n            for(int j=0;j<d;j++)\n            {\n                if(board[i][j]==min)\n                {\n                    if (min==(d*d)-1&&board[d-1][d-1]==0)\n                    {\n                        return true;\n                    }\n                }\n                \n                min=min+1;\n                \n            }\n            \n        }\n    \n        return false;\n\n}","undoManager":{"mark":-2,"position":27,"stack":[[{"start":{"row":286,"column":0},"end":{"row":286,"column":1},"action":"remove","lines":[" "],"id":1000}],[{"start":{"row":285,"column":21},"end":{"row":286,"column":7},"action":"remove","lines":["","       "],"id":1001}],[{"start":{"row":281,"column":12},"end":{"row":281,"column":16},"action":"remove","lines":["    "],"id":1002}],[{"start":{"row":281,"column":8},"end":{"row":281,"column":12},"action":"remove","lines":["    "],"id":1003}],[{"start":{"row":281,"column":4},"end":{"row":281,"column":8},"action":"remove","lines":["    "],"id":1004}],[{"start":{"row":281,"column":0},"end":{"row":281,"column":4},"action":"remove","lines":["    "],"id":1005}],[{"start":{"row":280,"column":0},"end":{"row":281,"column":0},"action":"remove","lines":["",""],"id":1006}],[{"start":{"row":277,"column":16},"end":{"row":278,"column":16},"action":"remove","lines":["","                "],"id":1007}],[{"start":{"row":277,"column":12},"end":{"row":277,"column":16},"action":"remove","lines":["    "],"id":1008}],[{"start":{"row":277,"column":8},"end":{"row":277,"column":12},"action":"remove","lines":["    "],"id":1009}],[{"start":{"row":277,"column":4},"end":{"row":277,"column":8},"action":"remove","lines":["    "],"id":1010}],[{"start":{"row":277,"column":0},"end":{"row":277,"column":4},"action":"remove","lines":["    "],"id":1011}],[{"start":{"row":276,"column":17},"end":{"row":277,"column":0},"action":"remove","lines":["",""],"id":1012}],[{"start":{"row":277,"column":26},"end":{"row":278,"column":0},"action":"remove","lines":["",""],"id":1013}],[{"start":{"row":277,"column":26},"end":{"row":278,"column":0},"action":"insert","lines":["",""],"id":1014},{"start":{"row":278,"column":0},"end":{"row":278,"column":16},"action":"insert","lines":["                "]}],[{"start":{"row":277,"column":16},"end":{"row":278,"column":0},"action":"insert","lines":["",""],"id":1015},{"start":{"row":278,"column":0},"end":{"row":278,"column":16},"action":"insert","lines":["                "]}],[{"start":{"row":254,"column":9},"end":{"row":255,"column":0},"action":"insert","lines":["",""],"id":1016},{"start":{"row":255,"column":0},"end":{"row":255,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":257,"column":0},"end":{"row":259,"column":0},"action":"insert","lines":["","    ",""],"id":1017}],[{"start":{"row":258,"column":0},"end":{"row":258,"column":4},"action":"remove","lines":["    "],"id":1018}],[{"start":{"row":257,"column":0},"end":{"row":258,"column":0},"action":"remove","lines":["",""],"id":1019}],[{"start":{"row":253,"column":8},"end":{"row":253,"column":12},"action":"remove","lines":["    "],"id":1020}],[{"start":{"row":253,"column":0},"end":{"row":253,"column":4},"action":"insert","lines":["    "],"id":1021}],[{"start":{"row":253,"column":4},"end":{"row":253,"column":8},"action":"insert","lines":["    "],"id":1022}],[{"start":{"row":253,"column":8},"end":{"row":253,"column":12},"action":"insert","lines":["    "],"id":1023}],[{"start":{"row":286,"column":0},"end":{"row":288,"column":0},"action":"insert","lines":["","    ",""],"id":1024}],[{"start":{"row":285,"column":4},"end":{"row":286,"column":0},"action":"insert","lines":["",""],"id":1025},{"start":{"row":286,"column":0},"end":{"row":286,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":288,"column":4},"end":{"row":289,"column":0},"action":"remove","lines":["",""],"id":1026}],[{"start":{"row":288,"column":0},"end":{"row":288,"column":4},"action":"remove","lines":["    "],"id":1027}]]},"ace":{"folds":[],"scrolltop":2953.423065185547,"scrollleft":306,"selection":{"start":{"row":15,"column":3},"end":{"row":15,"column":3},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1467621450954}