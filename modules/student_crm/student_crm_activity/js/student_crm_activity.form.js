(function($) {
  
  Drupal.behaviors.StudentCRMActivityForm = {
    
    attach : function() {
      if (Drupal.ajax && $('.ajax-loaded-view').hasClass('ajax-ready')) {
        if(!$('.ajax-loaded-view').hasClass('ajax-loading')) {
          $('.ajax-loaded-view').addClass('ajax-loading');
          $.get(window.location.href, function(data) {
            $('.ajax-loaded-view').first()
                                  .replaceWith($('.ajax-loaded-view:first', $(data)));
            var $firstActivity = $('.ajax-loaded-view .activity:first');
            var ogColor = $firstActivity.css('backgroundColor');
            $firstActivity.animate({ backgroundColor : '#ffffc5'}, 1000, function() {
              setTimeout(function() {
                $firstActivity.animate({ backgroundColor: ogColor}, 1000);
              }, 2000);
              $('.ajax-loaded-view').removeClass('ajax-loading');
            });
          });
        }
      }
      $('.ajax-loaded-view').addClass('ajax-ready');
    }
  };

})(jQuery);