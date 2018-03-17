from app import models, db
import datetime


############## useful queries ###############

# from app import models, db
# import datetime
# for movies in models.Movies.query.all():
#   print(movies.movieTitle)
#   print(movies.synopsis)
#   print(movies.rating)
#
# from app import models, db
# import datetime
# for screenings in models.Screenings.query.all():
#    print(models.Movies.query.filter_by(id=screenings.movies_id).first().movieTitle)
#    print(screenings.time)


# models.Movies.query.filter_by(id=screenings.movies_id).first().movieTitle
# a = models.Movies.query.filter_by(movieTitle="...").first()



############## useful queries ###############




############### del all relivant db tables ##############
for movies in models.Movies.query.all():
    db.session.delete(movies)
    db.session.commit()

for screenings in models.Screenings.query.all():
    db.session.delete(screenings)
    db.session.commit()


############### del all relivant db tables ##############

############### adding movie to Movies tables ##############
newMovieBlackPanther = models.Movies(movieTitle="Black Panther", synopsis="T'Challa, the King of Wakanda, rises to the throne in the isolated, technologically advanced African nation, but his claim is challenged by a vengeful outsider who was a childhood victim of T'Challa's father's mistake", rating=4)
newMovieTheGreatestShowman = models.Movies(movieTitle="The Greatest Showman", synopsis="Celebrates the birth of show business, and tells of a visionary who rose from nothing to create a spectacle that became a worldwide sensation.", rating=4.1)



#adding and commit the movies to the database
db.session.add(newMovieBlackPanther)
db.session.add(newMovieTheGreatestShowman)
db.session.commit()

############### adding movie to Movies tables ##############


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
blackPantherScreening1 = models.Screenings(movies_id=blackPatherID, time = screeningTime1)
blackPantherScreening2 = models.Screenings(movies_id=blackPatherID, time = screeningTime2)
blackPantherScreening3 = models.Screenings(movies_id=blackPatherID, time = screeningTime3)
blackPantherScreening4 = models.Screenings(movies_id=blackPatherID, time = screeningTime4)
blackPantherScreening5 = models.Screenings(movies_id=blackPatherID, time = screeningTime5)
blackPantherScreening6 = models.Screenings(movies_id=blackPatherID, time = screeningTime6)

 #assigning times to the greatest showman
theGreatestShowmanID = models.Movies.query.filter_by(movieTitle="The Greatest Showman").first().id
theGreatestShowmanScreening1 = models.Screenings(movies_id=theGreatestShowmanID, time = screeningTime7)
theGreatestShowmanScreening2 = models.Screenings(movies_id=theGreatestShowmanID, time = screeningTime8)
theGreatestShowmanScreening3 = models.Screenings(movies_id=theGreatestShowmanID, time = screeningTime9)




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
