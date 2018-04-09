from app import models, db
import datetime


############## useful queries ###############
#
# from app import models, db
# import datetime
# for movies in models.Movies.query.all():
#   print(movies.movieTitle)
#   print(movies.synopsis)
#   print(movies.ageRating)
#   print()
#
# from app import models, db
# import datetime
# for screens in models.Screen.query.all():
#   print(screens.screenName)
#   print(screens.Capacity)
#   print()
#
# from app import models, db
# import datetime
# for screenings in models.Screenings.query.all():
#    print(models.Movies.query.filter_by(id=screenings.movies_id).first().movieTitle)
#    print(screenings.screen_id)
#    print(screenings.time)
#    print()
#
# from app import models, db
# import datetime
# for seats in models.Seats.query.all():
#    print(seats)
#
# from app import models, db
# import datetime
# for seata in models.Seats.query.filter_by(row="A"):
#    print(seata)
#
# from app import models, db
# import datetime
# for row1 in models.Seats.query.filter_by(seatNumber=1):
#    print(row1)


# models.Movies.query.filter_by(id=screenings.movies_id).first().movieTitle
# a = models.Movies.query.filter_by(movieTitle="...").first()



############## useful queries ###############




############### del all relivant db tables ##############
for movies in models.Movies.query.all():
    db.session.delete(movies)
    db.session.commit()

for screen in models.Screen.query.all():
    db.session.delete(screen)
    db.session.commit()

for screenings in models.Screenings.query.all():
    db.session.delete(screenings)
    db.session.commit()

for seats in models.Seats.query.all():
    db.session.delete(seats)
    db.session.commit()

############### del all relivant db tables ##############

############### adding movie to Movies tables ##############
newMovieBlackPanther = models.Movies(movieTitle="Black Panther", synopsis="T'Challa, the King of Wakanda, rises to the throne in the isolated, technologically advanced African nation, but his claim is challenged by a vengeful outsider who was a childhood victim of T'Challa's father's mistake", ageRating="12A")
newMovieTheGreatestShowman = models.Movies(movieTitle="The Greatest Showman", synopsis="Celebrates the birth of show business, and tells of a visionary who rose from nothing to create a spectacle that became a worldwide sensation.", ageRating="PG")



#adding and commit the movies to the database
db.session.add(newMovieBlackPanther)
db.session.add(newMovieTheGreatestShowman)
db.session.commit()

############### adding movie to Movies tables ##############

############### adding screens to Screen tables ##############
screen1 = models.Screen(screenName="Screen 1", Capacity=35)
screen2 = models.Screen(screenName="Screen 2", Capacity=40)
screen3 = models.Screen(screenName="Screen 3", Capacity=20)


#adding and commit the movies to the database
db.session.add(screen1)
db.session.add(screen2)
db.session.add(screen3)
db.session.commit()

screen1ID = models.Screen.query.filter_by(screenName="Screen 1").first().screenName
screen2ID = models.Screen.query.filter_by(screenName="Screen 2").first().screenName
screen3ID = models.Screen.query.filter_by(screenName="Screen 3").first().screenName

############### adding screens to Screen tables ##############


############### adding screenings to Screenings tables ##############
#setting times for screenings
## 02/03/2018 at 6pm
screeningTime1 = datetime.datetime(2018, 2, 18, 12, tzinfo=datetime.timezone.utc)
screeningTime2 = datetime.datetime(2018, 2, 18, 18, tzinfo=datetime.timezone.utc)
screeningTime3 = datetime.datetime(2018, 2, 18, 20, tzinfo=datetime.timezone.utc)
screeningTime4 = datetime.datetime(2018, 2, 19, 12, tzinfo=datetime.timezone.utc)
screeningTime5 = datetime.datetime(2018, 2, 19, 18, tzinfo=datetime.timezone.utc)
screeningTime6 = datetime.datetime(2018, 2, 19, 20, tzinfo=datetime.timezone.utc)
screeningTime7 = datetime.datetime(2018, 3, 2, 9, tzinfo=datetime.timezone.utc)
screeningTime8 = datetime.datetime(2018, 3, 2, 14, tzinfo=datetime.timezone.utc)
screeningTime9 = datetime.datetime(2018, 3, 2, 21, tzinfo=datetime.timezone.utc)

#assigning times to black panther
blackPatherID = models.Movies.query.filter_by(movieTitle="Black Panther").first().id
blackPantherScreening1 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime1)
blackPantherScreening2 = models.Screenings(movies_id=blackPatherID, screen_id=screen2ID ,time = screeningTime2)
blackPantherScreening3 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime3)
blackPantherScreening4 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime4)
blackPantherScreening5 = models.Screenings(movies_id=blackPatherID, screen_id=screen3ID ,time = screeningTime5)
blackPantherScreening6 = models.Screenings(movies_id=blackPatherID, screen_id=screen3ID ,time = screeningTime6)

#assigning times to the greatest showman
theGreatestShowmanID = models.Movies.query.filter_by(movieTitle="The Greatest Showman").first().id
theGreatestShowmanScreening1 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen1ID ,time = screeningTime7)
theGreatestShowmanScreening2 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen2ID ,time = screeningTime8)
theGreatestShowmanScreening3 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen3ID , time = screeningTime9)




#adding and commit the screenings to the database
db.session.add(blackPantherScreening1)
db.session.add(blackPantherScreening2)
db.session.add(blackPantherScreening3)
db.session.add(blackPantherScreening4)
db.session.add(blackPantherScreening5)
db.session.add(blackPantherScreening6)

db.session.add(theGreatestShowmanScreening1)
db.session.add(theGreatestShowmanScreening2)
db.session.add(theGreatestShowmanScreening3)
db.session.commit()

############### adding screenings to Screenings tables ##############


############### adding seats to Seats tables ##############
rowA1 = models.Seats(row="A", seatNumber=1)
rowA2 = models.Seats(row="A", seatNumber=2)
rowA3 = models.Seats(row="A", seatNumber=3)
rowA4 = models.Seats(row="A", seatNumber=4)
rowA5 = models.Seats(row="A", seatNumber=5)
rowA6 = models.Seats(row="A", seatNumber=6)
rowA7 = models.Seats(row="A", seatNumber=7)
rowA8 = models.Seats(row="A", seatNumber=8)
rowA9 = models.Seats(row="A", seatNumber=9)
rowA10 = models.Seats(row="A", seatNumber=10)

rowB1 = models.Seats(row="B", seatNumber=1)
rowB2 = models.Seats(row="B", seatNumber=2)
rowB3 = models.Seats(row="B", seatNumber=3)
rowB4 = models.Seats(row="B", seatNumber=4)
rowB5 = models.Seats(row="B", seatNumber=5)
rowB6 = models.Seats(row="B", seatNumber=6)
rowB7 = models.Seats(row="B", seatNumber=7)
rowB8 = models.Seats(row="B", seatNumber=8)
rowB9 = models.Seats(row="B", seatNumber=9)
rowB10 = models.Seats(row="B", seatNumber=10)

rowC1 = models.Seats(row="C", seatNumber=1)
rowC2 = models.Seats(row="C", seatNumber=2)
rowC3 = models.Seats(row="C", seatNumber=3)
rowC4 = models.Seats(row="C", seatNumber=4)
rowC5 = models.Seats(row="C", seatNumber=5)
rowC6 = models.Seats(row="C", seatNumber=6)
rowC7 = models.Seats(row="C", seatNumber=7)
rowC8 = models.Seats(row="C", seatNumber=8)
rowC9 = models.Seats(row="C", seatNumber=9)
rowC10 = models.Seats(row="C", seatNumber=10)

rowD1 = models.Seats(row="D", seatNumber=1)
rowD2 = models.Seats(row="D", seatNumber=2)
rowD3 = models.Seats(row="D", seatNumber=3)
rowD4 = models.Seats(row="D", seatNumber=4)
rowD5 = models.Seats(row="D", seatNumber=5)
rowD6 = models.Seats(row="D", seatNumber=6)
rowD7 = models.Seats(row="D", seatNumber=7)
rowD8 = models.Seats(row="D", seatNumber=8)
rowD9 = models.Seats(row="D", seatNumber=9)
rowD10 = models.Seats(row="D", seatNumber=10)

rowE1 = models.Seats(row="E", seatNumber=1)
rowE2 = models.Seats(row="E", seatNumber=2)
rowE3 = models.Seats(row="E", seatNumber=3)
rowE4 = models.Seats(row="E", seatNumber=4)
rowE5 = models.Seats(row="E", seatNumber=5)
rowE6 = models.Seats(row="E", seatNumber=6)
rowE7 = models.Seats(row="E", seatNumber=7)
rowE8 = models.Seats(row="E", seatNumber=8)
rowE9 = models.Seats(row="E", seatNumber=9)
rowE10 = models.Seats(row="E", seatNumber=10)


#adding and commit the movies to the database
db.session.add(rowA1)
db.session.add(rowA2)
db.session.add(rowA3)
db.session.add(rowA4)
db.session.add(rowA5)
db.session.add(rowA6)
db.session.add(rowA7)
db.session.add(rowA8)
db.session.add(rowA9)
db.session.add(rowA10)

db.session.add(rowB1)
db.session.add(rowB2)
db.session.add(rowB3)
db.session.add(rowB4)
db.session.add(rowB5)
db.session.add(rowB6)
db.session.add(rowB7)
db.session.add(rowB8)
db.session.add(rowB9)
db.session.add(rowB10)

db.session.add(rowC1)
db.session.add(rowC2)
db.session.add(rowC3)
db.session.add(rowC4)
db.session.add(rowC5)
db.session.add(rowC6)
db.session.add(rowC7)
db.session.add(rowC8)
db.session.add(rowC9)
db.session.add(rowC10)

db.session.add(rowD1)
db.session.add(rowD2)
db.session.add(rowD3)
db.session.add(rowD4)
db.session.add(rowD5)
db.session.add(rowD6)
db.session.add(rowD7)
db.session.add(rowD8)
db.session.add(rowD9)
db.session.add(rowD10)

db.session.add(rowE1)
db.session.add(rowE2)
db.session.add(rowE3)
db.session.add(rowE4)
db.session.add(rowE5)
db.session.add(rowE6)
db.session.add(rowE7)
db.session.add(rowE8)
db.session.add(rowE9)
db.session.add(rowE10)

db.session.commit()

############### adding movie to Movies tables ##############
