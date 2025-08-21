# Testing the GitHub Copilot CI Setup

This document provides instructions for testing the GitHub Copilot CI integration.

## Quick Test

Run the validation script to verify the local setup:

```bash
./scripts/validate-copilot-ci.sh
```

This script will:
- ✅ Check system dependencies  
- ✅ Simulate the CI workflow
- ✅ Verify build and test configuration
- ✅ Provide feedback and next steps

## Workflow Testing

### Manual Trigger

You can manually test the workflow:

1. Go to the **Actions** tab in GitHub
2. Select "GitHub Copilot CI" workflow
3. Click "Run workflow" button
4. Choose the branch and click "Run workflow"

### Pull Request Testing

Create a test pull request to verify automatic execution:

1. Create a small change (e.g., add a comment to a file)
2. Push to a feature branch
3. Create a pull request to `main`
4. Verify the "GitHub Copilot CI" workflow runs automatically
5. Check that both jobs complete successfully:
   - "Quick validation" 
   - "Comprehensive tests (Ubuntu)"

## Expected Workflow Behavior

### Quick Validation Job (~5-10 minutes)
- Installs minimal dependencies
- Configures build with error handling
- Compiles the project
- Runs C++ tests (if dependencies available)
- Checks Python test setup

### Comprehensive Tests Job (~10-20 minutes)
- Only runs if Quick Validation passes
- Installs full dependencies including ccache
- Runs complete test suite (C++ and Python)
- Similar to existing `ci-linux.yml` workflow

## Status Checks

Once branch protection is configured, you'll see:
- ✅ **Quick validation** - Required status check
- ✅ **Comprehensive tests (Ubuntu)** - Required status check

Pull requests cannot be merged until both checks pass.

## Troubleshooting

### Workflow doesn't run automatically
- Check **Settings** → **Actions** → **General** permissions
- Verify "Fork pull request workflows from outside collaborators" is set appropriately

### Tests fail
- Check the workflow logs in the **Actions** tab
- Download error log artifacts for detailed information
- Common issues:
  - Missing dependencies (handled by CI)
  - Network connectivity (CI uses system packages where possible)
  - Test failures (indicates actual code issues)

### Status checks not enforced  
- Configure branch protection rules in **Settings** → **Branches**
- Add both job names as required status checks

## Success Criteria

The setup is working correctly when:
1. ✅ Workflow runs automatically on PR creation  
2. ✅ No manual approval required for collaborators
3. ✅ Both jobs complete successfully
4. ✅ Status checks block merging when tests fail
5. ✅ Error logs are available when builds fail

## GitHub Copilot Integration

With this setup, GitHub Copilot can:
- Create pull requests that automatically trigger testing
- Iterate on code changes based on test feedback
- Ensure code quality without manual intervention
- Work within the established CI/CD pipeline