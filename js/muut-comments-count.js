(function ($) {
  Drupal.behaviors.muut_comments_count = {
    attach: function (context, settings) {
      $("#muut-comments-count").once('counter', function() {
        var url = '//api.muut.com/postcounts?path=/' + Drupal.settings.muut_comments_count.path;
        $.getJSON(url, function(json) {
          var results = $("#muut-comments-count");
          $.each(json, function(key, val) {
            results.html(Drupal.t('@count comments', {'@count': val["size"]}));
          });
        });
      });

      $(".muut-comments-count-list-element").each(function(){
        var results = $(this);
        results.once('counter', function() {
          var path = $(this).data('path')
          var url = '//api.muut.com/postcounts?path=/' + path;
          $.getJSON(url, function(json) {
            $.each(json, function(key, val) {
              results.html(Drupal.t('@count comments', {'@count': val["size"]}));
            });
          });
        });
      });

    }
  }
})(jQuery);
