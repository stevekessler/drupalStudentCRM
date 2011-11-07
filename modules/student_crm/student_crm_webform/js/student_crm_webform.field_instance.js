(function($) {

  Drupal.behaviors.studentCRMWebformFieldSettings = {
    
    attach : function() {
      $('#edit-instance-settings-email-address').change(function() {
        if ($(this).val() == 'field') {
          $('#email-field-source-select').show();
        }
        else {
          $('#email-field-source-select').hide();
        }
      })
      .trigger('change');
    }
  };
})(jQuery);