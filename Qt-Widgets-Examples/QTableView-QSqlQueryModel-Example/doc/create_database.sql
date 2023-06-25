CREATE DATABASE localtest;

CREATE TABLE test
(
    id serial NOT NULL,
    two boolean,
    three character varying(200),
    four integer,
    five time without time zone,
    six double precision
);