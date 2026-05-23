<script lang="ts">
	import { resolve } from '$app/paths';
	import { page } from '$app/state';
	import github from '$lib/assets/github.svg';
	import { slide } from 'svelte/transition';
	import logo from '$lib/assets/favicon.svg';

	let isMenuOpen = $state(false);

	const navItems = [
		{ name: 'Home', path: '/' },
		{ name: 'About', path: '/about' },
		{ name: 'Docs', path: '/documentation' },
		{ name: 'download', path: '/download' }
	] as const;

	const checkActive = (currentPath: string, targetPath: string) => {
		if (targetPath === '/') return currentPath === '/';
		return currentPath.startsWith(targetPath);
	};
</script>

<header
	class="relative flex w-full items-center justify-between border-b border-zinc-200 bg-white px-6 py-4"
>
	<div class="z-20 flex items-center gap-2">
		<img src={logo} alt="Trace Logo" class="h-8 w-8 object-contain" />
		<a
			href={resolve('/')}
			class="text-xl font-black tracking-[0.2em] text-black uppercase transition-opacity hover:opacity-80"
		>
			race
		</a>
	</div>

	<button
		class="z-20 p-2 focus:outline-none md:hidden"
		onclick={() => (isMenuOpen = !isMenuOpen)}
		aria-label="Toggle menu"
	>
		<svg
			class="h-6 w-6 stroke-black transition-transform duration-300 {isMenuOpen ? 'rotate-90' : ''}"
			fill="none"
			viewBox="0 0 24 24"
			xmlns="http://www.w3.org/2000/svg"
		>
			{#if isMenuOpen}
				<path
					stroke-linecap="round"
					stroke-linejoin="round"
					stroke-width="2"
					d="M6 18L18 6M6 6l12 12"
				></path>
			{:else}
				<path
					stroke-linecap="round"
					stroke-linejoin="round"
					stroke-width="2"
					d="M4 6h16M4 12h16M4 18h16"
				></path>
			{/if}
		</svg>
	</button>

	<nav class="hidden md:block">
		<ul class="m-0 flex list-none items-center gap-8 p-0">
			{#each navItems as { name, path } (path)}
				{@const isActive = checkActive(page.url.pathname, path)}
				<li>
					<a
						href={resolve(path)}
						class="text-xs font-bold tracking-[0.15em] uppercase transition-colors {isActive
							? 'text-black'
							: 'text-zinc-500 hover:text-black'}"
						aria-current={isActive ? 'page' : undefined}
					>
						{name}
					</a>
				</li>
			{/each}
		</ul>
	</nav>

	<div class="hidden items-center justify-end md:flex">
		<a
			href="https://github.com/CoderSilicon"
			class="opacity-70 transition-opacity hover:opacity-100"
		>
			<img src={github} alt="GitHub" class="h-6 w-6 object-contain" />
		</a>
	</div>

	{#if isMenuOpen}
		<div
			transition:slide={{ duration: 250, axis: 'y' }}
			class="absolute top-full left-0 z-10 w-full border-b border-zinc-200 bg-white px-4 py-6 shadow-sm md:hidden"
		>
			<ul class="m-0 flex list-none flex-col gap-6 p-0 text-center">
				{#each navItems as { name, path } (path)}
					{@const isActive = checkActive(page.url.pathname, path)}
					<li>
						<a
							href={resolve(path)}
							onclick={() => (isMenuOpen = false)}
							class="block text-sm font-bold tracking-[0.15em] uppercase transition-colors {isActive
								? 'text-black'
								: 'text-zinc-500 hover:text-black'}"
						>
							{name}
						</a>
					</li>
				{/each}
				<li class="flex justify-center pt-2">
					<a
						href="https://github.com/CoderSilicon"
						onclick={() => (isMenuOpen = false)}
						class="opacity-70 hover:opacity-100"
					>
						<img src={github} alt="GitHub" class="h-6 w-6 object-contain" />
					</a>
				</li>
			</ul>
		</div>
	{/if}
</header>
