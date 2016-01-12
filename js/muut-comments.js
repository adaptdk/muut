(function ($) {
  Drupal.behaviors.muut_comments = {
    attach: function (context, settings) {
      $('#muut-comments').once('comments', function() {
        var gid = Drupal.settings.ogContext.gid;
  	$.extend(moot.language, {
  	  online: "Online",
  	  post: "Kommentér",
  	  reply: "Send et svar",
  	  watch: "Følg denne side",
  	  unwatch: "Følg ikke denne side",
  	  unwall: "Nulstil sider der følges",
  	  preview: "Forhåndsvisning",
  	  comment: "Skriv kommentar"
  	});
  	$.post( "/muut-comments/auth/" + gid , function( data ) {
  	  Drupal.settings.muut_comments.api  = data.api;
  	  $('#muut-comments').muut(Drupal.settings.muut_comments);
  	});
      });
    }
  }
})(jQuery);
