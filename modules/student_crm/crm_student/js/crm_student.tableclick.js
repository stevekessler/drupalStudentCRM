(function($) {
  Drupal.behaviors.CRMStudentTableClick = {
    
    attach : function() {
      $('.view.tableclick tr').each(function() {
          $(this).click(function() {
            window.location = $(this).find('a.tableclick-link:first').attr('href');
          });
      });
    }
  };
})(jQuery);