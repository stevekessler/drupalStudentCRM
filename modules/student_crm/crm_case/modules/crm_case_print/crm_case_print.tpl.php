<div id="print-contact">
	<h2>
		<?php print $contact_title; ?>
	</h2>
	<?php print $contact; ?>
</div>
<div id="print-case">
	<?php print $case; ?>
</div>
<div class="clear"></div>
<?php if(count($forms)): ?>
	<?php foreach($forms as $form): ?>
		<h2><?php print $form['form']; ?></h2>
		<?php foreach($form['submissions'] as $k => $submission): ?>
			<h3>
				<?php print t('Submission #%number', array('%number' => $k + 1)); ?>
			</h3>
			<div>
				<?php print $submission; ?>
			</div>
		<?php endforeach; ?>
	<?php endforeach; ?>

<?php endif; ?>