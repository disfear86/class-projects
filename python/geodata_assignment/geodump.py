#!/usr/bin/python3
import json
import sqlite3
import codecs

conn = sqlite3.connect('geodata.sqlite')
cur = conn.cursor()

cur.execute('SELECT * FROM Locations')
fhand = codecs.open('where.js', 'w', 'utf-8')
fhand.write("myData = [\n")
count = 0

for row in cur:
    data = str(row[1])
    #print(data)
    try:
        js = json.loads(str(data))
    except:
        continue
    if not ('status' in js and js['status'] == 'OK'):
        continue
    #print(js)
    lat = js['results'][0]['geometry']['location']['lat']
    lng = js['results'][0]['geometry']['location']['lng']
    if lat == 0 or lng == 0:
        continue
    where = js['results'][0]['formatted_address']
    where = where.replace("'","")
    try:
        print(where, lat, lng)
        count += 1
        if count > 1:
            fhand.write(",\n")
        output = "[{},{}, '{}']".format(str(lat),str(lng),where)
        fhand.write(output)
    except:
        continue
print(count)
fhand.write('\n];\n')
cur.close()
fhand.close()
print('Records written to where.js')
print('Open where.html to view the date in a browser')
