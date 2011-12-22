(function($) {
  Drupal.behaviors.holdSlider = {
    attach : function() {
      if($('.alert.holds').length) {
        this.attachHoldBehaviors();
      }
    },
    attachHoldBehaviors : function() {
      $('.alert.holds .body').addClass('element-invisible');
      $('.alert.holds .views-row h3').append('<a href="#" class="show-body">' + Drupal.t('more info') + '</a>');
      $('.alert.holds .views-row a.show-body').click(function() {
        var $body = $(this).parents('.views-row').find('.body');
        if($body.hasClass('element-invisible')) {
          $body.removeClass('element-invisible');
        }
        else {
          $body.addClass('element-invisible')
        }
        return false;
      });
    }
  };
})(jQuery);