(function($) {
  Drupal.behaviors.CRMTasks = {
    attach: function() {
      $('#show-add-tasks').fancybox({
        'onClosed' : function() {
          $('#edit-task-modal').addClass('element-invisible')
                         .parent('div')
                         .removeAttr('style');
        },
        'onStart'  : function() {
          $('#edit-task-modal').removeClass('element-invisible');
        },
        'autoDimensions' : false
      });
      $('#task-cancel').click(function() {
       $.fancybox.close();
      });
    }
  };

})(jQuery);