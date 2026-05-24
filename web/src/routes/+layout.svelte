<script lang="ts">
	import Header from '$lib/components/Header.svelte';
	import './layout.css';
	import './fonts.scss';
	import Footer from '$lib/components/Footer.svelte'

	let { children } = $props();
</script>

<div class="app bg-[#060709]">
	<Header />
	<main>{@render children()}</main>
	<Footer />
</div>
