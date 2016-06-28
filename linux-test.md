## 1. Create a bash file name `hello.sh`. It will work as follow:

```
./hello.sh NGUYEN
Hello NGUYEN!
Bonjour NGUYEN!
Xin Chao NGUYEN
```

## 2. Create a bash file name `my_cal.sh`. It will provide some basic math evaluation:

```
./my_cal.sh 12 14
sum: 26
mul: 168
```

## 3. Check if a document contains a word:

```
./search_word.sh  "Nguyen" mydocument.txt
yes
```

```
./search_word.sh  "Nguyen" mydocument1.txt
No
```

## 4. Count number of word/sentence/character in a document:

```
./count_word.sh mydocument.txt
155 words
29 sentences
700 characters
```

## 5. Find a document by name, if it exists then show the number of word, sentence and character:

```
./find_doc.sh mydocument.txt
The document exists
155 words
29 sentences
700 characters
```

```
./find_doc.sh mydocument.txt
Sorry, the document does not exist
```

## 6. Find all the document which contains a word:

```
./find_doc_word.sh "KeyWord" location/
mydocument.txt
mydocument3.txt
```

```
./find_doc_word.sh "KeyWord2" location/
There is no result
```



