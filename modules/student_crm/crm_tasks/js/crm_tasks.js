(function($) {
  Drupal.behaviors.CRMTasks = {
    attach: function() {
      $('#edit-task').addClass('element-invisible');
      $('#show-add-tasks').fancybox({
				'onClosed' : function() {
					$('#edit-task').addClass('element-invisible')
										.addClass('element-invisible');
				},
				'onStart'  : function() {
					$('#edit-task').removeClass('element-invisible');
				},
				'autoDimensions' : false
			});
			$('#task-cancel').click(function() {
			 $.fancybox.close();
			});
    }
  };

})(jQuery);