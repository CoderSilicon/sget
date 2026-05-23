<script lang="ts">
	import logo from '$lib/assets/favicon.svg';
	import { resolve } from '$app/paths';
</script>

<main class="min-h-screen w-full bg-white px-6 py-20 selection:bg-emerald-100/30">
	<article class="mx-auto max-w-3xl">
		<div class="mb-10 border-b border-zinc-200 pb-8">
			<div class="flex items-center gap-4">
				<img src={logo} alt="Trace" class="h-10 w-10 object-contain opacity-90" />
				<h1 class="text-4xl font-black tracking-[0.2em] text-black uppercase">RACE</h1>
			</div>
		</div>

		<div class="space-y-6 text-sm leading-relaxed text-zinc-800 md:text-base md:leading-relaxed">
			<p class="flex items-start gap-4">
				<!-- <span class="mt-1 text-zinc-400 select-none">01</span> -->
				<span>
					Trace is a <strong class="font-bold text-black"
						>lightning-fast, terminal-native utility</strong
					> for web data extracting. Built for pure functional workflow, frictionless from the ground
					up.
				</span>
			</p>

			<p class="flex items-start gap-4">
				<!-- <span class="mt-1 text-zinc-400 select-none">02</span> -->
				<span>
					No web bloat. No complex GUIs. Reincarnated from LinkBytes—colder, sharper, and designed
					entirely for your command line experience. Made with love by <a
						href="https://github.com/CoderSilicon"
						class="text-emerald-800 transition-colors hover:text-emerald-900 hover:underline"
					>
						@codersilicon</a
					>.
				</span>
			</p>

			<section class="flex items-start gap-4">
				<!-- <span class="mt-1 text-zinc-400 select-none">03</span> -->
				<div class="w-full">
					<span class="mb-2 block text-xs font-bold tracking-widest text-zinc-600 uppercase"
						>// Install & Get Started</span
					>

					<a
						href={resolve('/download')}
						class="group relative flex w-full max-w-lg items-center justify-between rounded bg-emerald-800 px-5 py-3 text-left text-white transition-all hover:bg-emerald-800/70"
					>
						<div class="flex items-center gap-4">Go to Downloads</div>
					</a>

					<span class="mt-2 block text-xs text-zinc-500"
						>// Ready to flow? Execute the command above to get started.</span
					>
				</div>
			</section>
		</div>
	</article>
</main>
