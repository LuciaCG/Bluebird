//Page Loader 

$(window).on('load', function () {
	$(".loader").fadeOut("slow");
});


//Navbar Javascript

$('.nav a').click(function () {
    $('.navbar-collapse').collapse('hide');
});

(function($) {
    "use strict"; // Start of use strict

    // Offset for Main Navigation
    $('#mainNav').affix({
        offset: {
            top: 50
        }
    })

})(jQuery); // End of use strict


$(document).ready(function(){  
	
	$(".navbar-default").addClass("nav-padding");
	$(".navbar-default").addClass("nav-trans");
	
	$(window).scroll(function() {
		if ($(".navbar-default").offset().top > 50) {
			$(".navbar-default").addClass("nav-no-padding");
		} else {
			$(".navbar-default").removeClass("nav-no-padding");
		}
	});

});

$(document).ready(function(){
  // Add smooth scrolling to all links
  $(".navbar-nav a").on('click', function(event) {

    // Make sure this.hash has a value before overriding default behavior
    if (this.hash !== "") {
      // Prevent default anchor click behavior
      event.preventDefault();

      // Store hash
      var hash = this.hash;

      // Using jQuery's animate() method to add smooth page scroll
      // The optional number (800) specifies the number of milliseconds it takes to scroll to the specified area
      $('html, body').animate({
        scrollTop: $(hash).offset().top
      }, 800, function(){
   
        // Add hash (#) to URL when done scrolling (default click behavior)
        window.location.hash = hash;
      });
    } // End if
  });
});


// Flex Slider

$(window).on('load',function(){
  $('.flexslider').flexslider({
	animation: "slide",
	start: function(slider){
	  $('body').removeClass('loading');
	}
  });
});

$('.flexslider').flexslider({
	animation: "slide",
	flexDirectionNav: false,
	controlNav: true,
	
});


//Tooltip

$(document).ready(function(){
    $('[data-toggle="tooltip"]').tooltip();   
});

//Owl Properties

$("#owl-rooms").owlCarousel({
 
	items : 3,
	itemsCustom : false,
	itemsDesktop : [1199,3],
	itemsDesktopSmall : [980,2],
	itemsTablet: [768,2],
	itemsTabletSmall: [600,1],
	itemsMobile : [479,1],
	singleItem : false,
	itemsScaleUp : false,
 
	//Autoplay
	autoPlay : true,
	stopOnHover : true,
 
	// Navigation
	navigation : true,
	navigationText : ['<i class="fa fa-angle-left" aria-hidden="true"></i>','<i class="fa fa-angle-right" aria-hidden="true"></i>'],
	rewindNav : true,
	scrollPerPage : false,
 
	//Pagination
	pagination : false,
	paginationNumbers: false,
 
	// Responsive 
	responsive: true,
	responsiveRefreshRate : 200,
	responsiveBaseWidth: window,    
});


// Owl Reviews

$("#owl-testimonial").owlCarousel({
	items : 3,
	itemsCustom : false,
	itemsDesktop : [1199,3],
	itemsDesktopSmall : [991,2],
	itemsTablet: [768,2],
	itemsTabletSmall: [500,2],
	itemsMobile : [479,1],
	singleItem : false,
	itemsScaleUp : false,
 
	//Autoplay
	autoPlay : true,
	stopOnHover : true,
 
	// Navigation
	loop : true,
	scrollPerPage : false,
 
	//Pagination
	pagination : false,
	paginationNumbers: false,
 
	// Responsive 
	responsive: true,
	responsiveRefreshRate : 200,
	responsiveBaseWidth: window,    
});