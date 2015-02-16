(function ($) {
	Drupal.behaviors.muut_comments = {
	  attach: function (context, settings) {
	    $.post( "/muut-comments/auth", function( data ) {
	      Drupal.settings.muut_comments.api  = data.api;
			  $("#muut-comments").muut(Drupal.settings.muut_comments);
	    });
	  }
	}
})(jQuery);