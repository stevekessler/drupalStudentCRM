(function($) {
  Drupal.behaviors.CRMBasket = {
    attach: function() {
      if(Drupal.settings.studentCRMBasketOff) {
        $('#show-basket').html('Cannot add to basket');
      }
      else {
        Drupal.behaviors.CRMBasket.setFancybox();
      }
      Drupal.behaviors.CRMBasket.addRemoveLinks();
    },
    
    setFancybox : function() {
      $('#show-basket').fancybox({
        'onClosed' : function() {
          $('#edit-basket-modal').addClass('element-invisible')
                         .parent('div')
                         .removeAttr('style');
        },
        'onStart'  : function() {
          $('#edit-basket-modal').removeClass('element-invisible');
        },
        'autoDimensions' : false
      });
      $('#basket-cancel').click(function() {
         $.fancybox.close();
         return false;
      });
    },
    
    addRemoveLinks : function() {
      $('.basket-link').click(function() {
        $link = $(this);
        $.getJSON($(this).attr('href'), function(data) {
          if(data.success) {
            if($link.hasClass('basket-remove')) {
              $link.removeClass('basket-remove')
                   .addClass('basket-add')
                   .attr('href', $link.attr('href').replace('/remove/', '/add/'))
                   .html(Drupal.t('Undo remove'));
            }
            else {
              $link.removeClass('basket-add')
                   .addClass('basket-remove')
                   .attr('href', $link.attr('href').replace('/add/', '/remove/'))
                   .html(Drupal.t('Remove'));
            }
          }
        });
        return false;
      });
    }
  };

})(jQuery);