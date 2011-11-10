(function($) {
  Drupal.behaviors.CRMTasksViews = {
    attach: function() {
      $('input.crm-task-mark:checked').each(function() {
        $(this).parents('tr:first')
               .addClass('completed');
      });
      $('input.crm-task-mark').change(function() {
        if($(this).is(':checked')) {
          var mark = 'mark';
        }
        else {
          var mark = 'unmark';
        }
        var $checkbox = $(this);
        $.getJSON(Drupal.settings.basePath + 'crm/tasks/mark/' + $(this).attr('data-rid') + '/' + mark, function(data) {
          if(data.mark) {
            $checkbox.parents('tr:first, li:first')
                     .addClass('completed');
          }
          else {
            $checkbox.parents('tr:first, li:first')
                     .removeClass('completed');
          }
        });
      });
    }
  };

})(jQuery);