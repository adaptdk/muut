(function ($) {
	Drupal.behaviors.muut_comments = {
	  attach: function (context, settings) {
      Drupal.settings.muut_comments = {};
		  Drupal.settings.muut_comments.conf = {
		    login_url: '//thehome.dk/login',
		    url: "https://muut.com/i/dsrcomments/comments:test",
		    show_online: true,
		    upload: false
		  };

	    $.post( "//dsr.dev/muut-comments/auth", function( data ) {
	      conf = Drupal.settings.muut_comments.conf;
	      conf.api  = data.api;
			  $("#muut-comments").muut(conf);
	    });
	  }
	}
})(jQuery);