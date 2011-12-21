(function($) {
  Drupal.behaviors.studentCRMGPAChart = {
    attach: function() {
      google.setOnLoadCallback(this.drawChart);
    },
    drawChart : function() {
    	var data = new google.visualization.DataTable();
        data.addColumn('string', 'Term');
        data.addColumn('number', 'Term GPA');
        data.addColumn('number', 'Cumulative GPA');
        $.getJSON(Drupal.settings.basePath + 'crm/contact/' + Drupal.settings.contact_id + '/gpa/json', function(gpa) {
        	$.each(gpa.items, function(index, item) {
        		data.addRow([item.item.term, parseFloat(item.item.term_gpa), parseFloat(item.item.gpa)]);
        	});
			var options = {
	          width: '100%', height: 240,
	        };
	
	        var chart = new google.visualization.LineChart(document.getElementById('gpa-chart'));
	        chart.draw(data, options);
        });
        
        
    }
  };
})(jQuery);