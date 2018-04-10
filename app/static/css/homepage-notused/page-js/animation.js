//Slide To Top Aniamtion

$(window).scroll(function() {
	$(".slide-top-vis").each(function(){
		var pos = $(this).offset().top;
		
		var winTop = $(window).scrollTop();
		if (pos < winTop + 600) {
		  $(this).addClass("slide-top");
		}
	})
});


//Slide To Bottom Aniamtion

$(window).scroll(function() {
	$(".slide-bot-vis").each(function(){
		var pos = $(this).offset().top;
		
		var winTop = $(window).scrollTop();
		if (pos < winTop + 600) {
		  $(this).addClass("slide-bot");
		}
	})
});


//Slide To Left Animation

$(window).scroll(function() {
	$(".slide-left-vis").each(function(){
		var pos = $(this).offset().top;
		
		var winTop = $(window).scrollTop();
		if (pos < winTop + 600) {
		  $(this).addClass("slide-left");
		}
	})
});


//Slide To Right Aniamtion

$(window).scroll(function() {
	$(".slide-right-vis").each(function(){
		var pos = $(this).offset().top;
		
		var winTop = $(window).scrollTop();
		if (pos < winTop + 600) {
		  $(this).addClass("slide-right");
		}
	})
});