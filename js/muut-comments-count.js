(function ($) {
  Drupal.behaviors.muut_comments_count = {
    attach: function (context, settings) {
      $("#muut-comments-count").once('counter', function() {
        var url = '//api.muut.com/postcounts?path=/' + Drupal.settings.muut_comments_count.path;
        $.getJSON(url, function(json) {
          var results = $("#muut-comments-count");
          $.each(json, function(key, val) {
            results.html(val["size"] + ' kommentarer');
          });
        });
      });
    }
  }
})(jQuery);
