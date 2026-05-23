<script lang="ts">
	import logo from '$lib/assets/favicon.svg';
</script>

<main class="min-h-screen w-full bg-white px-6 py-20 selection:bg-emerald-100/30">
	<article class="mx-auto max-w-3xl">
		<div class="mb-12 border-b border-zinc-200 pb-8">
			<div class="flex items-center gap-4">
				<img src={logo} alt="Trace" class="h-10 w-10 object-contain opacity-90" />
				<h1 class="text-4xl font-black tracking-[0.2em] text-black uppercase">RACE(1)</h1>
			</div>
		</div>

		<div class="space-y-12 text-sm leading-relaxed text-zinc-800 md:text-base md:leading-relaxed">
			<section>
				<h2 class="mb-3 font-bold tracking-widest text-zinc-400 uppercase">Name</h2>
				<div class="pl-4 md:pl-8">
					<strong class="text-black">trace</strong> - advance terminal web data extractor and analyzer
				</div>
			</section>

			<section>
				<h2 class="mb-3 font-bold tracking-widest text-zinc-400 uppercase">Synopsis</h2>
				<div class="pl-4 font-bold text-black md:pl-8">trace [OPTION]... [URL]</div>
			</section>

			<section>
				<h2 class="mb-3 font-bold tracking-widest text-zinc-400 uppercase">Description</h2>
				<div class="pl-4 md:pl-8">
					Trace fetches, parses, and extracts data from any given URL directly into your terminal.
					It bypasses heavy web browsers, providing instant insights into page metadata, content
					types, headers, and raw DOM extraction. Perfect for piping web data into other CLI tools.
				</div>
			</section>

			<section>
				<h2 class="mb-4 font-bold tracking-widest text-zinc-400 uppercase">Options</h2>
				<div class="space-y-6 pl-4 md:pl-8">
					<div class="grid grid-cols-1 gap-1 md:grid-cols-[180px_1fr] md:gap-4">
						<div class="font-bold text-black">-m, --meta</div>
						<div class="text-zinc-600">
							Extract page metadata including title, description, keywords, and OpenGraph tags.
						</div>
					</div>

					<div class="grid grid-cols-1 gap-1 md:grid-cols-[180px_1fr] md:gap-4">
						<div class="font-bold text-black">-t, --type</div>
						<div class="text-zinc-600">
							Identify content types and server headers (e.g., text/html, application/json).
						</div>
					</div>

					<div class="grid grid-cols-1 gap-1 md:grid-cols-[180px_1fr] md:gap-4">
						<div class="font-bold text-black">-x, --extract &lt;tag&gt;</div>
						<div class="text-zinc-600">
							Extract all instances of a specific HTML tag or CSS selector (e.g., 'a', 'h1',
							'.article-body').
						</div>
					</div>

					<div class="grid grid-cols-1 gap-1 md:grid-cols-[180px_1fr] md:gap-4">
						<div class="font-bold text-black">-j, --json</div>
						<div class="text-zinc-600">
							Format the extracted output as strict JSON, ideal for piping into jq or other parsers.
						</div>
					</div>

					<div class="grid grid-cols-1 gap-1 md:grid-cols-[180px_1fr] md:gap-4">
						<div class="font-bold text-black">-d, --dump</div>
						<div class="text-zinc-600">
							Dump the entire raw text content of the target URL, stripping away all HTML elements.
						</div>
					</div>
				</div>
			</section>

			<section>
				<h2 class="mb-4 font-bold tracking-widest text-zinc-400 uppercase">Examples</h2>
				<div class="space-y-6 pl-4 md:pl-8">
					<div>
						<div class="mb-2 text-xs font-bold tracking-widest text-zinc-500 uppercase">
							// Fetch all links from a page and format as JSON
						</div>
						<div
							class="overflow-x-auto rounded border border-zinc-200 bg-zinc-50 px-5 py-4 font-bold whitespace-nowrap text-black shadow-sm"
						>
							<span class="mr-3 text-zinc-400">$</span>trace --extract a --json
							https://github.com/codersilicon
						</div>
					</div>

					<div>
						<div class="mb-2 text-xs font-bold tracking-widest text-zinc-500 uppercase">
							// Grab site metadata quickly
						</div>
						<div
							class="overflow-x-auto rounded border border-zinc-200 bg-zinc-50 px-5 py-4 font-bold whitespace-nowrap text-black shadow-sm"
						>
							<span class="mr-3 text-zinc-400">$</span>trace -m https://svelte.dev
						</div>
					</div>
				</div>
			</section>
		</div>
	</article>
</main>
