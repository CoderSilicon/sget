<div
	class="flex min-h-screen flex-col bg-[#060709] px-6 py-24 font-sans text-[#a4a8b0] selection:bg-[#00f5c4]/30"
>
	<main class="relative z-10 mx-auto w-full max-w-3xl">
		<div class="mb-16 flex items-center justify-between border-b border-white/10 pb-4">
			<div class="flex gap-2">
				<span class="h-3 w-3 rounded-full bg-white/10"></span>
				<span class="h-3 w-3 rounded-full bg-white/10"></span>
				<span class="h-3 w-3 rounded-full bg-white/10"></span>
			</div>
			<span class="jetbrains-mono-400 text-xs text-[#545861]">~/about/the-author.md</span>
		</div>

		<header class="mb-16">
			<h1 class="jetbrains-mono-700 text-4xl leading-tight tracking-tight text-white md:text-5xl">
				I didn't set out to <br />
				<span class="text-[#00f5c4]">build a CLI.</span>
			</h1>
		</header>

		<article class="relative space-y-8 text-base leading-relaxed md:text-lg md:leading-loose">
			<p>
				For years, my workflow was fragmented. I just wanted to pull specific data from a website,
				but I always ended up chaining <code
					class="jetbrains-mono-400 rounded bg-white/5 px-1.5 py-0.5 text-white">curl</code
				>, <code class="jetbrains-mono-400 rounded bg-white/5 px-1.5 py-0.5 text-white">grep</code>,
				<code class="jetbrains-mono-400 rounded bg-white/5 px-1.5 py-0.5 text-white">sed</code>, and
				<code class="jetbrains-mono-400 rounded bg-white/5 px-1.5 py-0.5 text-white">jq</code>. It
				worked, but it was incredibly brittle—every time a website changed its markup even slightly,
				my entire pipeline broke.
			</p>

			<p>
				As my focus shifted deep into systems engineering, I realized my tools weren't keeping up.
				The solution was actually hiding in my own archives: an old, abandoned web-based link
				shortener called <em>LinkBytes</em> that I had built as an early learning project. It had sat
				gathering dust for years.
			</p>

			<div class="fade-to-void">
				<p>
					I stripped away the web interface, completely redesigned the core engine, and forged it
					into a lightning-fast tool built entirely for the command line. I built this because the
					best tools feel painfully obvious in retrospect; it is the exact, frictionless tool I wish
					I had five years ago.
				</p>
			</div>
		</article>
	</main>

	<div class="relative z-0 mt-32 flex min-h-[40vh] grow items-end justify-center pb-24">
		<span class="jetbrains-mono-700 animate-pulse text-xl text-[#034e3f]">_</span>
	</div>
</div>

<style>
	/* The visual fade effect into the background */
	.fade-to-void {
		-webkit-mask-image: linear-gradient(to bottom, black 20%, transparent 110%);
		mask-image: linear-gradient(to bottom, black 20%, transparent 110%);
	}
</style>
