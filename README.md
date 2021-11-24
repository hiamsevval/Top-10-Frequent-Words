# Top-10-Frequent-Words
This is a team project for CMP2003 Data Structures and Algorithms course coded in C++.
This is a C++ console application which reads files from Reuters-21578 documents collection appeared on the Reuters newswire in 1987 and find Top 10 frequent words used in the newswire articles.
Collection is distributed in 22 files. Each of the first 21 files contain 1000 document, while the last one contains 578 documents. First file name is reut2-000.sgm and the last one is reut2-021.sgm.
Each article starts with \<REUTERS TOPIC=?? LEWISSPLIT=?? CGISPLIT=?? OLDID=?? NEWID=??> where "??" are filled with appropriate fashion and ends with a "close tag" \</REUTERS>.
This program searches for only the words in between <body>...</body> tags. 
Also there is a stopwords list, stopwords.txt, that is supplied, these words are not counted in the result.
After processing the program prints top 10 frequent words used in the articles in descending order. Additionaly time elapsed from the beggining of the code and to the end of printing top 10 words calculated and printed.
Grading of this project is 70% for code and 30% for respect to running times compared with the all team projects.

P.S. This project got 100 points.
