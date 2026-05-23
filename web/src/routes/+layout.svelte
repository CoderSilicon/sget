<script lang="ts">
	import Header from '$lib/components/Header.svelte';
	import './layout.css';

	let { children } = $props();
</script>

<div class="app">
	<Header />
	<main>{@render children()}</main>
</div>
