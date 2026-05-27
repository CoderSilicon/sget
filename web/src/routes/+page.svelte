<script lang="ts">
	// import { resolve } from '$app/paths';
	// Terminal simulated output lines
	const terminalLines = [
		{ type: 'command', text: 'sget --links https://example.com ' },
		{ type: 'text', text: 'Connecting to example.com...' },
		{ type: 'status', text: 'Status: 200 OK' },
		{ type: 'text', text: 'Content-Type: text/html' },
		{ type: 'text', text: 'Found 12 links:' },
		{ type: 'link', text: '[1] https://example.com/about' },
		{ type: 'link', text: '[2] https://example.com/docs' },
		{ type: 'link', text: '[3] https://example.com/api/v2' },
		{ type: 'link', text: '[4] https://example.com/blog' },
		{ type: 'text', text: '...' }
	];

	const features = [
		{
			id: 'interactive-mode',
			title: 'Visuals',
			description: 'See the output in colorfull way and output which matters.',
			icon: '<path stroke-linecap="round" stroke-linejoin="round" d="M13 10V3L4 14h7v7l9-11h-7z" />'
		},
		{
			id: 'structured-output',
			title: 'Structured Output',
			description: 'Get clean JSON output; with all the necessary infos required',
			icon: '<path stroke-linecap="round" stroke-linejoin="round" d="M20 7l-8-4-8 4m16 0l-8 4m8-4v10l-8 4m0-10L4 7m8 4v10M4 7v10l8 4" />'
		},
		{
			id: 'smart-selectors',
			title: 'Simpilicity',
			description: 'Multiple flags which help you get what you "really" want',
			icon: '<path stroke-linecap="round" stroke-linejoin="round" d="M3 4a1 1 0 011-1h16a1 1 0 011 1v2.586a1 1 0 01-.293.707l-6.414 6.414a1 1 0 00-.293.707V17l-4 4v-6.586a1 1 0 00-.293-.707L3.293 7.293A1 1 0 013 6.586V4z" />'
		},
		{
			id: 'visual-diffs',
			title: 'Built-in File Support',
			description: 'Extracted data can be easily piped and stored into a file with just one flag.',
			icon: '<path stroke-linecap="round" stroke-linejoin="round" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />'
		}
	];

	const bulletPoints = [
		{ id: 'selectors', text: 'CSS and XPath selectors' },
		{ id: 'output', text: 'JSON, CSV, and table output' },
		{ id: 'redirects', text: 'Follow redirects & handle auth' },
		{ id: 'caching', text: 'Built-in caching & rate limiting' }
	];

	// Code examples for the right column box
	const codeExamples = [
		{
			id: 'extract-headings',
			comment: '# Pipe into files',
			command: ' sget --json https://archlinux.org --output logs.json'
		},
		{
			id: 'monitor-prices',
			comment: '# Security Check',
			command: 'sget --security https://fedoraproject.org'
		},
		{
			id: 'interactive-mode',
			comment: '# Interactive mode',
			command: 'sget --info https://api.example.com'
		}
	];
</script>

<section class="relative min-h-screen bg-[#060709] text-white ">
	<main class="mt-16 flex flex-col items-center px-5 text-center">
		<h1
			class="jetbrains-mono-400 mb-6 max-w-4xl font-sans text-[2.5rem] leading-[1.15] font-extrabold tracking-tight md:text-[4.2rem]"
		>
			Extract insights from <span class="text-[#002e23]">any website</span>
		</h1>

		<p class="jetbrains-mono-300 mb-10 max-w-2xl text-[1.05rem] leading-relaxed text-[#8e929a]">
			sget is a modern command-line tool for web data extraction.<br class="hidden md:inline" />
			Like curl, but interactive, visual, and built for humans.
		</p>

		<div class="mb-16 flex gap-4">
			<button
				class="jetbrains-mono-600 flex items-center gap-2 rounded bg-[#014e44] hover:bg-[#014e44b4] px-7 py-3.5 text-base font-bold text-zinc-100 transition-opacity hover:opacity-90"
			>
				Get Started
			</button>
			<button
				class="jetbrains-mono-200 rounded border border-white/10 bg-transparent px-7 py-3.5 text-base font-medium text-[#8e929a] transition-all hover:border-white/30 hover:text-white"
			>
				Read the docs
			</button>
		</div>

		<div
			class="w-full max-w-170 overflow-hidden rounded-s-md rounded-e-md border border-white/10 bg-[#0d0f13] text-left shadow-2xl"
		>
			<div class="border-bottom relative flex items-center border-white/4 bg-[#13161c] px-4 py-3">
				<div class="z-10 flex gap-2">
					<span class="h-2.5 w-2.5 rounded-full bg-[#ff5f56]"></span>
					<span class="h-2.5 w-2.5 rounded-full bg-[#ffbd2e]"></span>
					<span class="h-2.5 w-2.5 rounded-full bg-[#27c93f]"></span>
				</div>
				<div
					class="absolute inset-0 flex w-full items-center justify-center text-center text-xs text-[#61656e]"
				>
					sget
				</div>
			</div>

			<div class="jetbrains-mono-300 space-y-1.5 p-6 text-[0.95rem] leading-6">
				{#each terminalLines as line, i (i)}
					{#if line.type === 'command'}
						<p class="text-white">
							<span class="mr-2 text-[#013505] select-none">$</span>{line.text}
						</p>
					{:else if line.type === 'status'}
						<p class="font-semibold text-[#003000]">{line.text}</p>
					{:else if line.type === 'link'}
						<p class="text-[#093300]">{line.text}</p>
					{:else}
						<p class="text-[#a4a8b0]">{line.text}</p>
					{/if}
				{/each}
			</div>
		</div>
	</main>
</section>

<section
	class="flex justify-center bg-[#18181B] px-6 py-24 text-white selection:bg-[#00f5c4]/30 md:px-12"
>
	<div class="w-full max-w-6xl">
		<div class="mb-16 max-w-2xl">
			<h2 class="jetbrains-mono-400 mb-4 text-3xl font-bold tracking-tight md:text-4xl">
				<span class="text-white">sget</span> is a frontend built on libcurl.
			</h2>
			<p class="jetbrains-mono-300 font-mono text-sm leading-relaxed text-[#8e929a] md:text-base">
				Built for users who wants performance, simplicity, and only what they need; without complex
				notations.
			</p>
		</div>

		<div class="grid grid-cols-1 gap-5 md:grid-cols-2 lg:grid-cols-2">
			{#each features as feature (feature.id)}
				<div
					class="group rounded-2xl border border-white/8 bg-[#0d0f13] p-7 transition-all duration-300 hover:border-white/15"
				>
					<div
						class="mb-5 flex h-11 w-11 items-center justify-center rounded-xl bg-white/[0.03] text-[#00f5c4]"
					>
						<svg
							xmlns="http://www.w3.org/2000/svg"
							class="h-5 w-5"
							fill="none"
							viewBox="0 0 24 24"
							stroke="currentColor"
							stroke-width="2"
						>
							{@html feature.icon}
						</svg>
					</div>

					<h3 class="mb-2 font-mono text-[15px] font-semibold tracking-wide text-white">
						{feature.title}
					</h3>

					<p class="text-sm leading-7 text-[#8e929a]">
						{feature.description}
					</p>
				</div>
			{/each}
		</div>
	</div>
</section>

<section
	class="flex justify-center bg-[#060709] px-6 py-20 text-white selection:bg-[#00f5c4]/30 md:px-12"
>
	<div class="grid w-full max-w-6xl grid-cols-1 items-center gap-12 lg:grid-cols-12 lg:gap-8">
		<div class="space-y-6 lg:col-span-5">
			<h2 class="font-mono text-3xl leading-tight font-bold tracking-tight md:text-4xl">
				Simple syntax, <span class="block text-[#002e23] sm:inline">powerful results</span>
			</h2>

			<p class="max-w-lg font-mono text-sm leading-relaxed text-[#8e929a] md:text-base">
				Extract exactly what you need. No need to memorize cryptic flags.
			</p>

			<ul class="space-y-3.5 pt-2 font-mono text-sm md:text-base">
				{#each bulletPoints as point (point.id)}
					<li class="flex items-center text-[#a4a8b0]">
						<span class="mr-3.5 inline-block h-1.5 w-1.5 shrink-0 rounded-full bg-[#002e23]"></span>
						{point.text}
					</li>
				{/each}
			</ul>
		</div>

		<div class="lg:col-span-7">
			<div
				class="w-full space-y-6 rounded-xl border border-white/5 bg-[#0d0f13] p-6 font-mono text-sm leading-relaxed shadow-xl md:p-8 md:text-[0.95rem]"
			>
				{#each codeExamples as example (example.id)}
					<div class="space-y-1">
						<p class="text-[#545861] select-none">{example.comment}</p>
						<p class="break-all text-white">
							<span class="mr-2.5 text-[#175305] select-none">$</span>{example.command}
						</p>
					</div>
				{/each}
			</div>
		</div>
	</div>
</section>
<section
	class="jetbrains-mono-400 h-screen flex flex-col justify-center items-center bg-[#060709] px-6 pt-32 text-white selection:bg-[#00f5c4]/30 md:px-12"
>
	<div class="mb-36 flex max-w-2xl flex-col items-center text-center">
		<h2 class="jetbrains-mono-600 mb-5 text-3xl font-bold tracking-tight md:text-4xl">
			Ready to fetch?
		</h2>
		<p class="jetbrains-mono-300 mb-8 max-w-md text-sm leading-relaxed text-[#8e929a] md:text-base">
			Get started in seconds. Works on macOS, Linux, and Windows.
		</p>
		<button
			class="jetbrains-mono-300 flex items-center gap-2 rounded bg-[#002e23e5] px-7 py-3.5 font-sans text-base font-bold text-[#f8f8f8] transition-opacity hover:opacity-90"
		>
			Download sget <span class="text-lg">&rarr;</span>
		</button>
	</div>
</section>
