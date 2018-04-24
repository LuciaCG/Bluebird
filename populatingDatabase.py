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
# for seats in models.Seats.query.all():
#    print(seats.row)
#    print(seats.seatNumber)
#    print()
#
# from app import models, db
# import datetime
# for seata in models.Seats.query.filter_by(row="A"):
#    print(seats.rowSeatNumber)
#
# from app import models, db
# import datetime
# for row1 in models.Seats.query.filter_by(seatNumber=1):
#    print(seats.rowSeatNumber)
#
# from app import models, db
# import datetime
# for e in models.Employee.query.all():
#     print(e.id)
#     print(e.name)
#     print(e.password)
#     print()
#
# from app import models, db
# import datetime
# for u in models.Users.query.all():
#     print(u.id)
#     print(u.email)
#     print(u.name)
#     print(u.password)
#     print()
#
# for a in models.TypeOfTickets.query.all():
#     print(a.ticketType , (a.price))
#
# for a in models.Receipts.query.all():
#      b = models.Screenings.query.get(a.screening).movies_id
#      c = models.Movies.query.get(b).movieTitle
#      print(c)





# print(models.Seats.query.get(("A",1)))
# models.Movies.query.filter_by(id=screenings.movies_id).first().movieTitle
# a = models.Movies.query.filter_by(movieTitle="...").first()

#
# from app import models, db
# import datetime
# seatNumber = models.Seats.query.with_entities(models.Seats.seatNumber).group_by(models.Seats.seatNumber).all()
# rows = models.Seats.query.with_entities(models.Seats.row).group_by(models.Seats.row).all()
# x = 0
#
# for a in rows:
#     if x == 15:
#         break
#     print(a.row)
#     for b in seatNumber:
#         if x == 15:
#             break
#         c = models.Seats.query.filter_by(row = a.row, seatNumber = b.seatNumber).first()
#         print(b.seatNumber)
#         print(c.row , c.seatNumber)
#         x+=1
#         print(x)

# models.Seat_Reserved.query.filter_by(screening=1, rowReservedID=row, seatNumberReservedID=number).count()




############## useful queries ###############




############### del all relivant db tables ##############
for movies in models.Movies.query.all():
    db.session.delete(movies)
    db.session.commit()

for cards in models.CardDetails.query.all():
    db.session.delete(cards)
    db.session.commit()

for screen in models.Screen.query.all():
    db.session.delete(screen)
    db.session.commit()

for seatRes in models.Seat_Reserved.query.all():
    db.session.delete(seatRes)
    db.session.commit()

for screenings in models.Screenings.query.all():
    db.session.delete(screenings)
    db.session.commit()

for seats in models.Seats.query.all():
    db.session.delete(seats)
    db.session.commit()

for employee in models.Employee.query.all():
    db.session.delete(employee)
    db.session.commit()

for user in models.Users.query.all():
    db.session.delete(user)
    db.session.commit()

for ticket in models.TypeOfTickets.query.all():
    db.session.delete(ticket)
    db.session.commit()
############### del all relivant db tables ##############

############### adding movie to Movies tables ##############
newMovieIronMan = models.Movies(movieTitle="Iron Man", synopsis="After being held captive in an Afghan cave, billionaire engineer Tony Stark creates a unique weaponized suit of armor to fight evil.", ageRating="12A", director="Jon Favreau", leadActors="Robert Downey Jr., Terrence Howard, Gwyneth Paltrow, Jeff Bridges", moviePoster="static/images/IronManPoster.jpg", carasellPoster="static/images/image")
newMovieTheIncredibleHulk = models.Movies(movieTitle="The Incredible Hulk", synopsis="Bruce Banner, a scientist on the run from the U.S. Government, must find a cure for the monster he turns into, whenever he loses his temper.", ageRating="12", director="Louis Leterrier", leadActors="Edward Norton, Liv Tyler, Tim Roth", moviePoster="static/images/HulkPoster.jpg", carasellPoster="static/images/image")
newMovieIronMan2 = models.Movies(movieTitle="Iron Man 2", synopsis="With the world now aware of his identity as Iron Man, Tony Stark must contend with both his declining health and a vengeful mad man with ties to his father's legacy.", ageRating="12", director="Jon Favreau", leadActors="Robert Downey Jr., Don Cheadle, Gwyneth Paltrow, Scarlett Johansson, Mickey Rourke,", moviePoster="static/images/IronMan2Poster.jpg", carasellPoster="static/images/image")
newMovieThor = models.Movies(movieTitle="Thor", synopsis="The powerful, but arrogant god Thor, is cast out of Asgard to live amongst humans in Midgard (Earth), where he soon becomes one of their finest defenders.", ageRating="12", director="Kenneth Branagh", leadActors="Chris Hemsworth, Anthony Hopkins, Natalie Portman", moviePoster="static/images/ThorPoster.jpg", carasellPoster="static/images/image")
newMovieCaptainAmericaTFA = models.Movies(movieTitle="Captain America: The First Avenger", synopsis="Steve Rogers, a rejected military soldier transforms into Captain America after taking a dose of a \"Super-Soldier serum\". But being Captain America comes at a price as he attempts to take down a war monger and a terrorist organization.", ageRating="12", director="Joe Johnston", leadActors="Chris Evans, Hugo Weaving, Samuel L. Jackson, Hayley Atwell", moviePoster="static/images/CaptainAmerica1Poster.jpg", carasellPoster="static/images/image")
newMovieTheAvengers = models.Movies(movieTitle="Avengers Assemble", synopsis="Earth's mightiest heroes must come together and learn to fight as a team if they are going to stop the mischievous Loki and his alien army from enslaving humanity.", ageRating="12", director="Joss Whedon", leadActors="Robert Downey Jr., Chris Evans, Scarlett Johansson, Mark Ruffalo, Chris Hemsworth, Tom Hiddleston", moviePoster="static/images/Avengers1Poster.jpg", carasellPoster="static/images/image")
newMovieIronMan3 = models.Movies(movieTitle="Iron Man 3", synopsis="When Tony Stark's world is torn apart by a formidable terrorist called the Mandarin, he starts an odyssey of rebuilding and retribution.", ageRating="12", director="Shane Black", leadActors="Robert Downey Jr., Guy Pearce, Gwyneth Paltrow", moviePoster="static/images/IronMan3Poster.jpg", carasellPoster="static/images/image")
newMovieThorTheDarkWorld = models.Movies(movieTitle="Thor: The Dark World", synopsis="When Dr. Jane Foster gets cursed with a powerful entity known as the Aether, Thor is heralded of the cosmic event known as the Convergence and the genocidal Dark Elves.", ageRating="12", director="Alan Taylor", leadActors="Chris Hemsworth, Natalie Portman, Christopher Eccleston", moviePoster="static/images/Thor2Poster.jpg", carasellPoster="static/images/image")
newMovieCaptainAmericaTWS = models.Movies(movieTitle="Captain America: The Winter Soldier", synopsis="As Steve Rogers struggles to embrace his role in the modern world, he teams up with a fellow Avenger and S.H.I.E.L.D agent, Black Widow, to battle a new threat from history: an assassin known as the Winter Soldier.", ageRating="12", director="Joe Russo, Anthony Russo", leadActors="Chris Evans, Samuel L. Jackson, Scarlett Johansson, Robert Redford, Sebastian Stan, Anthony Mackie", moviePoster="static/images/CaptainAmerica2Poster.jpg", carasellPoster="static/images/image")
newMovieGuardiansoftheGalaxy = models.Movies(movieTitle="Guardians of the Galaxy", synopsis="A group of intergalactic criminals are forced to work together to stop a fanatical warrior from taking control of the universe.", ageRating="12", director="James Gunn", leadActors="Chris Pratt, Zoe Saldana, Dave Bautista, Bradley Cooper, Vin Diesel, Lee Pace", moviePoster="static/images/GoGPoster.jpg", carasellPoster="static/images/guardiansOfTheGalaxyWidePoster.jpg")
newMovieAvengersAOU = models.Movies(movieTitle="Avengers: Age of Ultron", synopsis="When Tony Stark and Bruce Banner try to jump-start a dormant peacekeeping program called Ultron, things go horribly wrong and it's up to Earth's mightiest heroes to stop the villainous Ultron from enacting his terrible plan.", ageRating="12", director="Joss Whedon", leadActors="Robert Downey Jr., Chris Evans, Mark Ruffalo, Chris Hemsworth, James Spader", moviePoster="static/images/Avengers2Poster.jpg", carasellPoster="static/images/image")
newMovieAntMan = models.Movies(movieTitle="Ant-Man", synopsis="Forced out of his own company by former protege Darren Cross, Dr. Hank Pym (Michael Douglas) recruits the talents of Scott Lang (Paul Rudd), a master thief just released from prison. Lang becomes Ant-Man, trained by Pym and armed with a suit that allows him to shrink in size, possess superhuman strength and control an army of ants. The miniature hero must use his new skills to prevent Cross, also known as Yellowjacket, from perfecting the same technology and using it as a weapon for evil.", ageRating="12A", director="Peyton Reed", leadActors="Paul Rudd, Michael Douglas, Corey Stoll, Evangeline Lilly", moviePoster="static/images/Ant-ManPoster.jpg", carasellPoster="static/images/image")
newMovieCaptainAmericaCivilWar = models.Movies(movieTitle="Captain America: Civil War", synopsis="Political pressure mounts to install a system of accountability when the actions of the Avengers lead to collateral damage. The new status quo deeply divides members of the team. Captain America (Chris Evans) believes superheroes should remain free to defend humanity without government interference. Iron Man (Robert Downey Jr.) sharply disagrees and supports oversight. As the debate escalates into an all-out feud, Black Widow (Scarlett Johansson) and Hawkeye (Jeremy Renner) must pick a side.", ageRating="12A", director="Anthony Russo, Joe Russo", leadActors="Chris Evans, Robert Downey Jr., Scarlett Johansson", moviePoster="static/images/CaptainAmericaCivilWarPoster.jpg", carasellPoster="static/images/CaptainAmericaCivilWar.jpg")
newMovieDoctorStrange = models.Movies(movieTitle="Doctor Strange", synopsis="While on a journey of physical and spiritual healing, a brilliant neurosurgeon is drawn into the world of the mystic arts.", ageRating="12A", director="Scott Derrickson", leadActors="Benedict Cumberbatch, Chiwetel Ejiofor, Rachel McAdams, Tilda Swinton, Mads Mikkelsen", moviePoster="static/images/DoctorStrangePoster.jpg", carasellPoster="static/images/image")
newMovieGuardiansoftheGalaxy2 = models.Movies(movieTitle="Guardians of the Galaxy: Vol. 2", synopsis="The Guardians must fight to keep their newfound family together as they unravel the mystery of Peter Quill's true parentage.", ageRating="12A", director="James Gunn", leadActors="Chris Pratt, Zoe Saldana, Dave Bautista, Bradley Cooper, Vin Diesel, Kurt Russell", moviePoster="static/images/GoG2Poster.jpg", carasellPoster="static/images/guardiansOfTheGalaxyWidePoster.jpg")
newMovieSpiderManHomecoming = models.Movies(movieTitle="Spider-Man: Homecoming", synopsis="Thrilled by his experience with the Avengers, young Peter Parker returns home to live with his Aunt May. Under the watchful eye of mentor Tony Stark, Parker starts to embrace his newfound identity as Spider-Man. He also tries to return to his normal daily routine -- distracted by thoughts of proving himself to be more than just a friendly neighborhood superhero. Peter must soon put his powers to the test when the evil Vulture emerges to threaten everything that he holds dear.", ageRating="12A", director="Jon Watts", leadActors="Tom Holland, Michael Keaton, Robert Downey Jr.", moviePoster="static/images/SpidermanHomecomingPoster.jpg", carasellPoster="static/images/image")
newMovieThorRagnarok = models.Movies(movieTitle="Thor: Ragnarok", synopsis="Thor is imprisoned on the planet Sakaar, and must race against time to return to Asgard and stop Ragnarok, the destruction of his world, which is at the hands of the powerful and ruthless villain Hela.", ageRating="12A", director="Taika Waititi", leadActors="Chris Hemsworth, Tom Hiddleston, Cate Blanchett, Mark Ruffalo", moviePoster="static/images/ThorRagnarokPoster.jpg", carasellPoster="static/images/ThorCaresellPoster.jpg")
newMovieBlackPanther = models.Movies(movieTitle="Black Panther", synopsis="T'Challa, the King of Wakanda, rises to the throne in the isolated, technologically advanced African nation, but his claim is challenged by a vengeful outsider who was a childhood victim of T'Challa's father's mistake", ageRating="12A", director="Ryan Coogler", leadActors="Chadwick Boseman, Michael B. Jordan, Lupita Nyong'o", moviePoster="static/images/Black-Panther-poster.jpg", carasellPoster="static/images/image")
newMovieAvengersIW = models.Movies(movieTitle="Avengers: Infinity War", synopsis="The Avengers and their allies must be willing to sacrifice all in an attempt to defeat the powerful Thanos before his blitz of devastation and ruin puts an end to the universe.", ageRating="12A", director="Anthony Russo, Joe Russo", leadActors="Robert Downey Jr., Chris Evans, Chris Hemsworth, Karen Gillan, Tom Holland, Scarlett Johansson, Chris Pratt, Zoe Saldana", moviePoster="static/images/Avengers3Poster.jpg", carasellPoster="static/images/image")
newMovieAntManandtheWasp = models.Movies(movieTitle="Ant-Man and the Wasp", synopsis="As Scott Lang balances being both a Super Hero and a father, Hope van Dyne and Dr. Hank Pym present an urgent new mission that finds the Ant-Man fighting alongside The Wasp to uncover secrets from their past.", ageRating="12A", director="Peyton Reed", leadActors="Hannah John-Kamen, Paul Rudd, Evangeline Lilly", moviePoster="static/images/Ant-Man2Poster.jpeg", carasellPoster="static/images/image")
newMovieCaptainMarvel = models.Movies(movieTitle="Captain Marvel", synopsis="Carol Danvers becomes one of the universe's most powerful heroes when Earth is caught in the middle of a galactic war between two alien races.", ageRating="12A", director="Anna Boden, Ryan Fleck", leadActors="Ben Mendelsohn, Brie Larson, Lee Pace", moviePoster="static/images/CaptainMarvel.jpg", carasellPoster="static/images/image")
newMovieAvengers4 = models.Movies(movieTitle="Untitled Avengers Movie", synopsis="The plot is yet to be revealed. Will be the 4th installment of the 'Avengers' series.", ageRating="12A", director="Anthony Russo, Joe Russo", leadActors="Robert Downey Jr., Chris Evans, Chris Hemsworth, Karen Gillan, Tom Holland, Scarlett Johansson, Chris Pratt, Zoe Saldana", moviePoster="static/images/image", carasellPoster="static/images/image")

#thor Ragnarok
#Civil
#GoG


#adding and commit the movies to the database
db.session.add(newMovieIronMan)
db.session.add(newMovieTheIncredibleHulk)
db.session.add(newMovieIronMan2)
db.session.add(newMovieThor)
db.session.add(newMovieCaptainAmericaTFA)
db.session.add(newMovieTheAvengers)
db.session.add(newMovieIronMan3)
db.session.add(newMovieThorTheDarkWorld)
db.session.add(newMovieCaptainAmericaTWS)
db.session.add(newMovieGuardiansoftheGalaxy)
db.session.add(newMovieAvengersAOU)
db.session.add(newMovieAntMan)
db.session.add(newMovieCaptainAmericaCivilWar)
db.session.add(newMovieDoctorStrange)
db.session.add(newMovieGuardiansoftheGalaxy2)
db.session.add(newMovieSpiderManHomecoming)
db.session.add(newMovieThorRagnarok)
db.session.add(newMovieBlackPanther)
db.session.add(newMovieAvengersIW)
db.session.add(newMovieAntManandtheWasp)
db.session.add(newMovieCaptainMarvel)
db.session.add(newMovieAvengers4)
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

# screen1ID = models.Screen.query.filter_by(screenName="Screen 1").first().screenName
# screen2ID = models.Screen.query.filter_by(screenName="Screen 2").first().screenName
# screen3ID = models.Screen.query.filter_by(screenName="Screen 3").first().screenName

############### adding screens to Screen tables ##############

currentDay = datetime.datetime.now().date()
dates = []
for i in range(1,9):
  newCurrentDays= currentDay + datetime.timedelta(days=i)
  dates.append(newCurrentDays)

for i in dates:
  print(i.year , i.month , i.day)

dayCount = 0
screenCount = 1
for i in models.Movies.query.all():
  screeningTime1 = datetime.datetime(dates[dayCount].year,dates[dayCount].month, dates[dayCount].day, 12 , tzinfo=datetime.timezone.utc)
  screeningTime2 = datetime.datetime(dates[dayCount].year,dates[dayCount].month, dates[dayCount].day, 15 , tzinfo=datetime.timezone.utc)
  screeningTime3 = datetime.datetime(dates[dayCount].year,dates[dayCount].month, dates[dayCount].day, 18 , tzinfo=datetime.timezone.utc)
  if(screenCount == 1):
      screening1 = models.Screenings(movies_id=i.id, screen_id="Screen 1" ,time = screeningTime1)
      screening2 = models.Screenings(movies_id=i.id, screen_id="Screen 1" ,time = screeningTime2)
      screening3 = models.Screenings(movies_id=i.id, screen_id="Screen 1" ,time = screeningTime3)
      screenCount += 1
  elif(screenCount == 2):
      screening1 = models.Screenings(movies_id=i.id, screen_id="Screen 2" ,time = screeningTime1)
      screening2 = models.Screenings(movies_id=i.id, screen_id="Screen 2" ,time = screeningTime2)
      screening3 = models.Screenings(movies_id=i.id, screen_id="Screen 2" ,time = screeningTime3)
      screenCount += 1
  elif(screenCount == 3):
      screening1 = models.Screenings(movies_id=i.id, screen_id="Screen 3" ,time = screeningTime1)
      screening2 = models.Screenings(movies_id=i.id, screen_id="Screen 3" ,time = screeningTime2)
      screening3 = models.Screenings(movies_id=i.id, screen_id="Screen 3" ,time = screeningTime3)
      screenCount = 1
      dayCount += 1
  else:
      print("something went wrong")
  db.session.add(screening1)
  db.session.add(screening2)
  db.session.add(screening3)
  db.session.commit()


############### adding screenings to Screenings tables ##############
#setting times for screenings
## 02/03/2018 at 6pm
# screeningTime1 = datetime.datetime(2018, 2, 18, 12, tzinfo=datetime.timezone.utc)
# screeningTime2 = datetime.datetime(2018, 2, 18, 18, tzinfo=datetime.timezone.utc)
# screeningTime3 = datetime.datetime(2018, 2, 18, 20, tzinfo=datetime.timezone.utc)
# screeningTime4 = datetime.datetime(2018, 2, 19, 12, tzinfo=datetime.timezone.utc)
# screeningTime5 = datetime.datetime(2018, 2, 19, 18, tzinfo=datetime.timezone.utc)
# screeningTime6 = datetime.datetime(2018, 2, 19, 20, tzinfo=datetime.timezone.utc)
# screeningTime7 = datetime.datetime(2018, 3, 2, 9, tzinfo=datetime.timezone.utc)
# screeningTime8 = datetime.datetime(2018, 3, 2, 14, tzinfo=datetime.timezone.utc)
# screeningTime9 = datetime.datetime(2018, 3, 2, 21, tzinfo=datetime.timezone.utc)
#
#  #assigning times to black panther
# blackPatherID = models.Movies.query.filter_by(movieTitle="Black Panther").first().id
# blackPantherScreening1 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime1)
# blackPantherScreening2 = models.Screenings(movies_id=blackPatherID, screen_id=screen2ID ,time = screeningTime2)
# blackPantherScreening3 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime3)
# blackPantherScreening4 = models.Screenings(movies_id=blackPatherID, screen_id=screen1ID ,time = screeningTime4)
# blackPantherScreening5 = models.Screenings(movies_id=blackPatherID, screen_id=screen3ID ,time = screeningTime5)
# blackPantherScreening6 = models.Screenings(movies_id=blackPatherID, screen_id=screen3ID ,time = screeningTime6)

#  #assigning times to the greatest showman
# theGreatestShowmanID = models.Movies.query.filter_by(movieTitle="The Greatest Showman").first().id
# theGreatestShowmanScreening1 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen1ID ,time = screeningTime7)
# theGreatestShowmanScreening2 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen2ID ,time = screeningTime8)
# theGreatestShowmanScreening3 = models.Screenings(movies_id=theGreatestShowmanID, screen_id=screen3ID , time = screeningTime9)




#adding and commit the screenings to the database
# db.session.add(blackPantherScreening1)
# db.session.add(blackPantherScreening2)
# db.session.add(blackPantherScreening3)
# db.session.add(blackPantherScreening4)
# db.session.add(blackPantherScreening5)
# db.session.add(blackPantherScreening6)
# #
# db.session.add(theGreatestShowmanScreening1)
# db.session.add(theGreatestShowmanScreening2)
# db.session.add(theGreatestShowmanScreening3)
# db.session.commit()


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


############### Seat Reserved table tests ##################
# from app import models, db
# import datetime

# a = models.Seat_Reserved(screening=1, rowReservedID="A", seatNumberReservedID=4)
# b = models.Seat_Reserved(screening=1, rowReservedID="A", seatNumberReservedID=1)
# c = models.Seat_Reserved(screening=1, rowReservedID="B", seatNumberReservedID=4)
# d = models.Seat_Reserved(screening=2, rowReservedID="A", seatNumberReservedID=4)
# e = models.Seat_Reserved(screening=1, rowReservedID="B", seatNumberReservedID=2)
# f = models.Seat_Reserved(screening=1, rowReservedID="E", seatNumberReservedID=4)
# g = models.Seat_Reserved(screening=4, rowReservedID="A", seatNumberReservedID=4)
#
# db.session.add(a)
# db.session.add(b)
# db.session.add(c)
# db.session.add(d)
# db.session.add(e)
# db.session.add(f)
# db.session.add(g)
#
# db.session.commit()

############### Seat Reserved table tests ##################


############### adding employees to empoyees tables ##############

employeeOnline = models.Employee(name="online", password="online")
tempEmployee = models.Employee(name="temp empoyee 1", password="password123")

db.session.add(employeeOnline)
db.session.add(tempEmployee)

db.session.commit()

############### adding employees to empoyees tables ##############

############### adding unsers to empoyees tables ##############

guestUser = models.Users(name="guest", password="password123", email="guest@cinema.com")
PeteUser = models.Users(name="Pete", password="peter1234", email="sc16ph@leeds.ac.uk")
DomUser = models.Users(name="Dom", password="dominic1234", email="sc16dah@leeds.ac.uk")
FreddieUser = models.Users(name="Freddie", password="freddie1234", email="sc15fr@leeds.ac.uk")
StefanUser = models.Users(name="Stefan", password="stefan1234", email="sc16sr@leeds.ac.uk")
RoryUser = models.Users(name="Rory", password="rory1234", email="sc16rk@leeds.ac.uk")
LuciaUser = models.Users(name="Lucia", password="lucia1234", email="sc17lc@leeds.ac.uk")

db.session.add(guestUser)
db.session.add(PeteUser)
db.session.add(DomUser)
db.session.add(FreddieUser)
db.session.add(StefanUser)
db.session.add(RoryUser)
db.session.add(LuciaUser)

db.session.commit()

############### adding users to empoyees tables ##############

############### adding type of ticket to TypeOfTickets tables ##############

child = models.TypeOfTickets(ticketType = "Child", price=6.5)
adult = models.TypeOfTickets(ticketType = "Adult", price=9)
senior = models.TypeOfTickets(ticketType = "Senior", price=7)
VIP = models.TypeOfTickets(ticketType = "VIP", price=12)


db.session.add(child)
db.session.add(adult)
db.session.add(senior)
db.session.add(VIP)

db.session.commit()

############### adding type of ticket to TypeOfTickets tables ##############
a = models.Receipts(userName="guest", employeeName="online", screening=1, price=9, pricePaid=9, change=0, transactionTime=datetime.datetime.utcnow())
db.session.add(a)
db.session.commit()

###################### encryption queries ###########################
# from app import models, db
# import datetime
# import hashlib

###### practice card details #####
a = models.CardDetails(userID=1, cardNickname="Card1", cardNumber="4556939797103693", exMonth="11", exYear="2018")
b = models.CardDetails(userID=1, cardNickname="Card2", cardNumber="0123456789123456", exMonth="11", exYear="2018")
db.session.add(a)
db.session.add(b)
db.session.commit()
#
#
# for a in models.CardDetails.query.all():
#      print(a.userID , a.cardNumber)

##########################################################

# cardNumber = "4556939797103693"
# newCardNumber = ""
#
# for character in range(0,16):
#   if (character % 3) == 0:
#     changedLetter = ord(cardNumber[character]) - 3
#   elif (character % 2) == 0:
#     changedLetter = ord(cardNumber[character]) - 2
#   else:
#     changedLetter = ord(cardNumber[character]) - 1
#   newCardNumber += chr(changedLetter)
#
#
# cardNumber = newCardNumber
# cardNumber

##########################################################

# newCardNumber = ""
#
# for character in range(12,16):
#   if (character % 3) == 0:
#     changedLetter = ord(cardNumber[character]) + 3
#   elif (character % 2) == 0:
#     changedLetter = ord(cardNumber[character]) + 2
#   else:
#     changedLetter = ord(cardNumber[character]) + 1
#   newCardNumber += chr(changedLetter)
#
#
# cardNumber = newCardNumber
# cardNumber

##########################################################

# newCardNumber = ""
#
# for character in range(12,16):
#   if (character % 3) == 0:
#     changedLetter = ord(a.cardNumber[character]) + 3
#   elif (character % 2) == 0:
#     changedLetter = ord(a.cardNumber[character]) + 2
#   else:
#     changedLetter = ord(a.cardNumber[character]) + 1
#   newCardNumber += chr(changedLetter)
#
#
# newCardNumber

##########################################################

# for character in range(0,16):
#   index=
#   print(index)
#   if (index%3) == 0:
#     print("mod3")
#   elif (index%2) == 0:
#     print("mod2")
#   else:
#     print("odd")

###################### encryption queries ###########################
