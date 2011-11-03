(function($) {

  Drupal.behaviors.studentCRMWebformSendForm = {
    
    attach : function() {
      
      $('#student-crm-webform-send-email-form .form-select').change(function() {
        if(Drupal.settings.studentCRMWebformSettings[$(this).val()] == 'manual') {
          $('#student-crm-webform-send-email-form .form-item-manual-email').show();
        }
        else {
          $('#student-crm-webform-send-email-form .form-item-manual-email').hide();
        }
      })
      .trigger('change');
    }
  };
})(jQuery);