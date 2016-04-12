# milier
a search engineering implement with C++

I intend to implement a search engineering, I do not use mature tools because I want to learn the basic
search engineering skills.

I call it as milier, just I like it.

In my thoughts, the search engineering will including follows part:
  1. crawler
  2. data base a.storage b.cache
  3. indexer
  4. word segment algorithm
  5. parser
  6. milier
  
The basic architecture is:


  crawler1  -----|		    |---indexer1
  crawler2  -----|		    |---indexer2
  crawler3  -----|		    |---indexer3
  crawler4  -----|	==>db/mq ==>|---indexer4 ==>db ==>milier
  ........  ---..|		    |---...
  crawlern  -----|		    |---indexern	|
  				    |			|
					|		|
					|		|
  		     words segment-------		|
				cache--------------------
									
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
