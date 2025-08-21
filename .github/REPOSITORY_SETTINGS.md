# GitHub Repository Configuration

This document describes the recommended settings for enabling GitHub Agent automation on this repository.

## Branch Protection Rules (for `main` branch)

To enable full GitHub Agent automation, configure the following branch protection rules via GitHub's web interface:

### Required Settings:
- **Require pull request reviews before merging**: ✓
  - Required approving reviews: 0 (allows auto-merge of Agent PRs)
  - Dismiss stale reviews: ✓
  - Require review from CODEOWNERS: ✗ (disable for automated PRs)

- **Require status checks to pass before merging**: ✓
  - Require branches to be up to date before merging: ✓
  - Required status checks:
    - `Quick Test (Ubuntu Latest)`
    - `ci on ghcr.io/themachinethatgoesping/ubuntu-dep:latest`
    - `ci on ubuntu:22.04`
    - `ci on archlinux`

- **Require signed commits**: ✗ (disable for GitHub Actions automation)

- **Require linear history**: ✓ (optional, helps keep history clean)

- **Allow force pushes**: ✗

- **Allow deletions**: ✗

### GitHub Actions Permissions

In repository Settings → Actions → General:

- **Actions permissions**: "Allow all actions and reusable workflows"
- **Artifact and log retention**: 90 days (or as needed)
- **Fork pull request workflows**: "Require approval for first-time contributors"

### Auto-merge Settings

- **Allow auto-merge**: ✓ (required for automated merging)
- **Automatically delete head branches**: ✓ (keeps repository clean)

## GitHub Agent/Copilot Integration

The repository is configured to:

1. **Automatically run tests** on all pull requests, including those created by GitHub Copilot
2. **Provide detailed feedback** via PR comments when tests fail
3. **Auto-approve and merge** successful PRs from GitHub agents
4. **Guide developers** on how to fix test failures using Copilot

### Workflow Overview

1. **PR Creation**: When a PR is created (by Copilot or manually):
   - `copilot-ci.yml` workflow runs quick validation tests
   - On success, triggers full CI suite (`ci-linux.yml`, etc.)

2. **Test Failure**: When tests fail:
   - `auto-fix-pr.yml` workflow adds helpful comments
   - Guides users to use Copilot for fixes
   - Adds labels for tracking

3. **Test Success**: When all tests pass:
   - Auto-approval for agent-created PRs
   - Automatic merge with squash commits
   - Cleanup of failure-related labels

### Special Branch Naming

PRs with branches matching these patterns get special treatment:
- `copilot/*`: Created by GitHub Copilot
- Any PR by `github-actions[bot]` or `copilot[bot]`

## Dependencies Management

- **Dependabot** is configured to automatically update:
  - GitHub Actions versions (weekly)
  - Python dependencies (weekly)
- Dependabot PRs will also trigger the automated test suite

## Manual Override

Repository maintainers can always:
- Manually review and merge any PR
- Override automated decisions
- Adjust workflow triggers as needed
- Modify branch protection rules

The automation is designed to assist, not replace, human judgment.