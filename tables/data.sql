﻿-- Table: nutron_food

-- DROP TABLE nutron_food;

CREATE TABLE nutron_food
(
  food_id serial NOT NULL,
  name text,
  description text,
  calorificvalue integer,
  image text,
  classification text,
  CONSTRAINT x_id_pkey PRIMARY KEY (food_id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE nutron_food
  OWNER TO admin;