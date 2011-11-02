(function($) {

  Drupal.behaviors.studentCRMWebformFancybox = {
    
    attach : function() {
      $('.webform-entity-modal li a').each(function() {
        if(typeof $(this).fancybox !== 'undefined') {
          var $link = $(this);
          $(this).fancybox({
            type   : 'ajax',
            width  : '80%',
            height : '80%',
            autoDimensions: false,
            ajax : { 
                     type       : "GET",
                     url        : $link.attr('href'),
                     dataFilter : function(data) {
                       return $(data).find('#block-system-main')[0];
                     }
                    }
          });
        }
      });
    }
  };
})(jQuery);