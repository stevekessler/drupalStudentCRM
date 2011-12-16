(function($) {
  
  Drupal.behaviors.StudentCRMEasyCopy = {
    
    attach : function() {
      $('.easy-copy').click(function() {
        var size = $(this).innerWidth();
        var content = $(this).text();
        var $input = $('<input>').attr('value', content)
                               .addClass('easy-copy')
                               .css('width', (size + 15) + 'px');
        $(this).replaceWith($input);
        $input.select();
      });
    }
  };

})(jQuery);