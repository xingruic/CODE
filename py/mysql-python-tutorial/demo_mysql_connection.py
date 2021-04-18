import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="ubuntu",
  password="huanhuanchen"
)

print(mydb)
