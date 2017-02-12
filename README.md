# milier
a search engineering implement with C++

I'm intend to implement a search enginerring, before I just want to learn
some basic skills. But now, I want to use frameworks to implement, because
I'm not a coder.

In my thoughts, the search engineering will including those parts:
  1. crawler
  2. data base
    * storage
    * cache
  3. indexer
  4. word segment algorithm
  5. parser
  6. milier
  
The basic architecture is:

              db
            /
    crawler -db     => words segment => index => milier
            \                             |        ^
             db                         cache------|


we use crawler to crawl the website every result is a web page, then crawler put
the pages into the db or mq. The crawler is a distribute systerm.

db/mq we just want to storage the data temple, but we want high performance. So
redis or zeroMQ maybe good for us.

words segment is segment the sentence into words, most usefull is 2-gram. Here we
use more time to implement the words segment.

indexer module, we should define the most completely data structure to create the
inverted index. The most popular data structure for full text search is inverted index.
Here we use inverted index also.

milier is ouput entry for the input, for query we also need words segment and visit
the inverted index to find inverted index lists. Then we should use logic compute to
search what result users wanted.

Contact me:
  author : youngcy
  email  : youngcy.youngcy@gmail.com
