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
  
  Drupal.behaviors.scrollMultipage = {
    attach : function() {
      $('.multipage-button a, .multipage-button input').click(function() { 
        $('html, body').scrollTop($("#page").offset().top);
      });
    }
  };
  
  Drupal.theme.prototype.multipage = function (settings) {
    var controls = {};
    controls.item = $('<span class="multipage-button"></span>');
    controls.item.append(controls.nextLink = $('<input type="button" class="form-submit multipage-link-next" value="" />').val(controls.nextTitle = Drupal.t('Next page')));
    controls.item.prepend(controls.previousLink = $('<a class="multipage-link-previous element-invisible" href="#"></a>'));
    if (!settings.has_next) {
      controls.nextLink.hide();
    }
    if (settings.has_previous) {
      controls.previousLink.append(controls.previousTitle = $('<strong></strong>').text(Drupal.t('Previous')))
                           .removeClass('element-invisible');
    }
    return controls;
  };

  
})(jQuery);