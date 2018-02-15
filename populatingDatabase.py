from app import models, db

#be careful not to run the same movie twice otherwise it will be in the database twice

newFilm1 = models.Movies(movieTitle="Test Movie Script", synopsis="test 5", rating=5)

db.session.add(newFilm1)
db.session.commit()


newFilm1 = models.Movies(movieTitle="Test Movie Script2", synopsis="test 6", rating=4)

db.session.add(newFilm1)
db.session.commit()



newFilm1 = models.Movies(movieTitle="Test Movie Script3", synopsis="test 6", rating=3)

db.session.add(newFilm1)
db.session.commit()


newFilm1 = models.Movies(movieTitle="Test Movie Script4", synopsis="test 7", rating=2)

db.session.add(newFilm1)
db.session.commit()
