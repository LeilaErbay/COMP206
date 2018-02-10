#!/usr/bin/env python
import csv, cgi, sys, urllib2

print "Content-type: text/html\n\n"

def room(manna=10,gold=0):
    print """   
    <!DOCTYPE html>

<html>
    <head>
        <link rel = "stylesheet" href="css/style.css">
    </head>
    <body>
    <h1 class="center"> The COMP206 Triumvirate Welcomes You </h1>


        <div id = "room">
            <img src = "https://s-media-cache-ak0.pinimg.com/originals/f4/36/05/f436054ad4e780016f1a4420bfd0ffa6.jpg" width = "800" height = "500">

            <div class = "transport_buttons_container">
                <form class = "button north_button" action = "http://www.cs.mcgill.ca/~tspark1/cgi-bin/transporter.py" method = "post">
                    <input type = "hidden" name = "inventory" value = "%(manna)d, %(gold)d">
                    <input type = "hidden" name = "URL" value = "www.cs.mcgill.ca/~lerbay/cgi-bin/room.html">
                    <input type="submit" value ="NORTH">
                </form>

                <form class = "button east_button" action = "http://cgi.cs.mcgill.ca/~rtao10/ass4/transporter.py" method = "post">
                    <input type = "hidden" name = "inventory" value = "%(manna)d, %(gold)d">
                    <input type = "hidden" name = "URL" value = "www.cs.mcgill.ca/~lerbay/cgi-bin/room.html">
                    <input type="submit" value ="EAST">
                </form>

                <form class = "button west_button" action = "http://cs.mcgill.ca/~rke/jungleroom/cgi-bin/transporter.py" method = "post">
                    <input type = "hidden" name = "inventory" value = "%(manna)d, %(gold)d">
                    <input type = "hidden" name = "URL" value = "www.cs.mcgill.ca/~lerbay/cgi-bin/room.html">
                    <input type="submit" value ="WEST">
                </form>

                <form class = "button south_button" action = "http://cs.mcgill.ca/~rgao11/cgi-bin/transporter.py" method = "post">
                    <input type = "hidden" name = "inventory" value = "%(manna)d, %(gold)d">
                    <input type = "hidden" name = "URL" value = "www.cs.mcgill.ca/~lerbay/cgi-bin/room.html">
                    <input type="submit" value ="SOUTH">
                </form>
            </div>
		 <p> Please enter ONE of the following commands below </p>
                <p> REFRESH | to refresh the page </p>
                <p> PLAY | to begin playing our awesome game </p>
                <p> EXIT | to exit  the entire dungeon game </p>
                <p> DROP n | to drop a certain amount of gold, n is a number value </p>

            <form class = "submit" action = "room.cgi" method = "post">    <!-- change name of file -->
                <input type="text" name="command" size="35">
                <input type="hidden" name="inventory" value="10,10">
                <input type="submit">
            </form>
        </div>

    </body>
</html>

 """%{ 'manna' : manna, 'gold' : gold}

csvfile = open("resources.csv","rb")
csvread = csv.reader(csvfile,delimiter=",")
resources = list(csvread)
#print resources

#if room is occupied
if resources[0][2] is '1':

    URL = cgi.FieldStorage().getvalue('URL')


    #print "Content-type: text/html\n\n"
    print "<html><head><title>CGI</title></head>"
    print "<body>"
    print '<h1 class="center"> Sorry, our room is occupied... </h1>'
    print '<h4 class="centre">Click below to go back </h4>'
    print '<form name="direction" action="%s" method="POST">'%(URL)
    print '<input type="submit" name="direction" value="Back to where you came from"/>'
    print '</form>'
    print "</body>"
    print "</html>"
#if available
else:
    #access room.html    
    #(manna, gold) = ((cgi.FieldStorage()).getvalue('inventory')).split(", ")
    form = cgi.FieldStorage()
    inventory = form.getvalue('inventory', '100,100') #this is for testing
    (manna, gold) = inventory.split(",")
    manna = int(manna)
    gold = int(gold)
    resources[0][2] = '1' 
    csv_file = open("resources.csv","wb")
    wr = csv.writer(csv_file)
    wr.writerows(resources)
    csv_file.close()
    #writing to csv
    room(manna,gold)

