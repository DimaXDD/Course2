use Lab6_Java;

--DELETE FROM books;
--DELETE FROM authors;

CREATE TABLE Books (
  id INT NOT NULL,
  title VARCHAR(255) NOT NULL,
  authors VARCHAR(255) NOT NULL,
  year INT NOT NULL,
  publisher VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE Authors (
  id INT NOT NULL,
  full_name VARCHAR(255) NOT NULL,
  country VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE Book_Authors (
  book_id INT NOT NULL,
  author_id INT NOT NULL,
  FOREIGN KEY (book_id) REFERENCES books(id),
  FOREIGN KEY (author_id) REFERENCES authors(id),
  PRIMARY KEY (book_id, author_id)
);